/*
 * @lc app=leetcode.cn id=2742 lang=cpp
 * @lcpr version=30204
 *
 * [2742] 给墙壁刷油漆
 *
 * https://leetcode.cn/problems/painting-the-walls/description/
 *
 * algorithms
 * Hard (37.98%)
 * Likes:    52
 * Dislikes: 0
 * Total Accepted:    5.6K
 * Total Submissions: 12.7K
 * Testcase Example:  '[1,2,3,2]\n[1,2,3,2]'
 *
 * 给你两个长度为 n 下标从 0 开始的整数数组 cost 和 time ，分别表示给 n 堵不同的墙刷油漆需要的开销和时间。你有两名油漆匠：
 * 
 * 
 * 一位需要 付费 的油漆匠，刷第 i 堵墙需要花费 time[i] 单位的时间，开销为 cost[i] 单位的钱。
 * 一位 免费 的油漆匠，刷 任意 一堵墙的时间为 1 单位，开销为 0 。但是必须在付费油漆匠 工作 时，免费油漆匠才会工作。
 * 
 * 
 * 请你返回刷完 n 堵墙最少开销为多少。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：cost = [1,2,3,2], time = [1,2,3,2]
 * 输出：3
 * 解释：下标为 0 和 1 的墙由付费油漆匠来刷，需要 3 单位时间。同时，免费油漆匠刷下标为 2 和 3 的墙，需要 2 单位时间，开销为 0
 * 。总开销为 1 + 2 = 3 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：cost = [2,3,4,2], time = [1,1,1,1]
 * 输出：4
 * 解释：下标为 0 和 3 的墙由付费油漆匠来刷，需要 2 单位时间。同时，免费油漆匠刷下标为 1 和 2 的墙，需要 2 单位时间，开销为 0
 * 。总开销为 2 + 2 = 4 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= cost.length <= 500
 * cost.length == time.length
 * 1 <= cost[i] <= 10^6
 * 1 <= time[i] <= 500
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
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();        
        vector<int> dp(2 * n + 1, INT_MAX / 2);
        dp[n] = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> tmp(2 * n + 1, INT_MAX / 2);
            for (int j = 0; j <= 2 * n; ++j) {
                tmp[min(2 * n, j + time[i])] = min(tmp[min(2 * n, j + time[i])], dp[j] + cost[i]);
                if (j > 0) {
                    tmp[j - 1] = min(tmp[j - 1], dp[j]);
                }
            }
            dp = move(tmp);
        }

        return *min_element(dp.begin() + n, dp.end());
    }
};

// @lc code=end



/*
// @lcpr case=start
// [1,2,3,2]\n[1,2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4,2]\n[1,1,1,1]\n
// @lcpr case=end

 */

