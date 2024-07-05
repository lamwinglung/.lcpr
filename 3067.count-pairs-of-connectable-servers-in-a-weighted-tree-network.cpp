/*
 * @lc app=leetcode.cn id=3067 lang=cpp
 * @lcpr version=30202
 *
 * [3067] 在带权树网络中统计可连接服务器对数目
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
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<vector<pair<int,int>>> graph(n);
        for (auto &edge : edges) {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);
        }

        function<int(int, int, int)> dfs = [&](int parent, int curr, int currCost) {
            int count = 0;
            if (currCost == 0) {
                ++count;
            }
            for (auto &[next, cost] : graph[curr]) {
                if (next != parent) {
                    count += dfs(curr, next, (currCost + cost) % signalSpeed);
                }
            }
            return count;
        };

        vector<int> ans(n, 0);
        for (int u = 0; u < n; ++u) {
            int sum = 0;
            for (auto [v, cost] : graph[u]) {
                int count = dfs(u, v, cost % signalSpeed);
                ans[u] += (sum * count);
                sum += count;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1,1],[1,2,5],[2,3,13],[3,4,9],[4,5,2]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[0,6,3],[6,5,3],[0,3,1],[3,2,7],[3,1,6],[3,4,2]]\n3\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,1]]\n3\n
// @lcpr case=end

 */

