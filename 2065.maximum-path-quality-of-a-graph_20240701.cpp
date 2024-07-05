/*
 * @lc app=leetcode.cn id=2065 lang=cpp
 * @lcpr version=30204
 *
 * [2065] 最大化一张图中的路径价值
 *
 * https://leetcode.cn/problems/maximum-path-quality-of-a-graph/description/
 *
 * algorithms
 * Hard (54.97%)
 * Likes:    51
 * Dislikes: 0
 * Total Accepted:    8.6K
 * Total Submissions: 13.1K
 * Testcase Example:  '[0,32,10,43]\n[[0,1,10],[1,2,15],[0,3,10]]\n49'
 *
 * 给你一张 无向 图，图中有 n 个节点，节点编号从 0 到 n - 1 （都包括）。同时给你一个下标从 0 开始的整数数组 values ，其中
 * values[i] 是第 i 个节点的 价值 。同时给你一个下标从 0 开始的二维整数数组 edges ，其中 edges[j] = [uj, vj,
 * timej] 表示节点 uj 和 vj 之间有一条需要 timej 秒才能通过的无向边。最后，给你一个整数 maxTime 。
 * 
 * 合法路径 指的是图中任意一条从节点 0 开始，最终回到节点 0 ，且花费的总时间 不超过 maxTime
 * 秒的一条路径。你可以访问一个节点任意次。一条合法路径的 价值 定义为路径中 不同节点 的价值 之和 （每个节点的价值 至多 算入价值总和中一次）。
 * 
 * 请你返回一条合法路径的 最大 价值。
 * 
 * 注意：每个节点 至多 有 四条 边与之相连。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：values = [0,32,10,43], edges = [[0,1,10],[1,2,15],[0,3,10]], maxTime = 49
 * 输出：75
 * 解释：
 * 一条可能的路径为：0 -> 1 -> 0 -> 3 -> 0 。总花费时间为 10 + 10 + 10 + 10 = 40 <= 49 。
 * 访问过的节点为 0 ，1 和 3 ，最大路径价值为 0 + 32 + 43 = 75 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：values = [5,10,15,20], edges = [[0,1,10],[1,2,10],[0,3,10]], maxTime = 30
 * 输出：25
 * 解释：
 * 一条可能的路径为：0 -> 3 -> 0 。总花费时间为 10 + 10 = 20 <= 30 。
 * 访问过的节点为 0 和 3 ，最大路径价值为 5 + 20 = 25 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 输入：values = [1,2,3,4], edges = [[0,1,10],[1,2,11],[2,3,12],[1,3,13]],
 * maxTime = 50
 * 输出：7
 * 解释：
 * 一条可能的路径为：0 -> 1 -> 3 -> 1 -> 0 。总花费时间为 10 + 13 + 13 + 10 = 46 <= 50 。
 * 访问过的节点为 0 ，1 和 3 ，最大路径价值为 1 + 2 + 4 = 7 。
 * 
 * 示例 4：
 * 
 * 
 * 
 * 输入：values = [0,1,2], edges = [[1,2,10]], maxTime = 10
 * 输出：0
 * 解释：
 * 唯一一条路径为 0 。总花费时间为 0 。
 * 唯一访问过的节点为 0 ，最大路径价值为 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == values.length
 * 1 <= n <= 1000
 * 0 <= values[i] <= 10^8
 * 0 <= edges.length <= 2000
 * edges[j].length == 3 
 * 0 <= uj < vj <= n - 1
 * 10 <= timej, maxTime <= 100
 * [uj, vj] 所有节点对 互不相同 。
 * 每个节点 至多有四条 边。
 * 图可能不连通。
 * 
 * 
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<vector<pair<int,int>>> g(n);

        for (auto &edge : edges) {
            g[edge[0]].emplace_back(edge[1], edge[2]);
            g[edge[1]].emplace_back(edge[0], edge[2]);
        }

        int maxValue = 0;
        vector<bool> visited(n, false);
        visited[0] = true;
        function<void(int,int,int)> backtrace = [&](int value, int timeSum, int u) {
            if (u == 0) {
                maxValue = max(value, maxValue);
            }
            for (auto [v, time] : g[u]) {
                if (time + timeSum <= maxTime) {
                    if (!visited[v]) {
                        visited[v] = true;
                        backtrace(value + values[v], time + timeSum, v);
                        visited[v] = false;
                    } else {
                        backtrace(value, time + timeSum, v);
                    }
                }
            }
        };
        backtrace(values[0], 0, 0);
        return maxValue;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,32,10,43]\n[[0,1,10],[1,2,15],[0,3,10]]\n49\n
// @lcpr case=end

// @lcpr case=start
// [5,10,15,20]\n[[0,1,10],[1,2,10],[0,3,10]]\n30\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n[[0,1,10],[1,2,11],[2,3,12],[1,3,13]]\n50\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2]\n[[1,2,10]]\n10\n
// @lcpr case=end

 */

