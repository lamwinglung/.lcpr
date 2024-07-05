/*
 * @lc app=leetcode.cn id=2741 lang=cpp
 * @lcpr version=30204
 *
 * [2741] 特别的排列
 *
 * https://leetcode.cn/problems/special-permutations/description/
 *
 * algorithms
 * Medium (37.15%)
 * Likes:    54
 * Dislikes: 0
 * Total Accepted:    6.8K
 * Total Submissions: 15.8K
 * Testcase Example:  '[2,3,6]'
 *
 * 给你一个下标从 0 开始的整数数组 nums ，它包含 n 个 互不相同 的正整数。如果 nums
 * 的一个排列满足以下条件，我们称它是一个特别的排列：
 * 
 * 
 * 对于 0 <= i < n - 1 的下标 i ，要么 nums[i] % nums[i+1] == 0 ，要么 nums[i+1] % nums[i]
 * == 0 。
 * 
 * 
 * 请你返回特别排列的总数目，由于答案可能很大，请将它对 10^9 + 7 取余 后返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [2,3,6]
 * 输出：2
 * 解释：[3,6,2] 和 [2,6,3] 是 nums 两个特别的排列。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,4,3]
 * 输出：2
 * 解释：[3,1,4] 和 [4,1,3] 是 nums 两个特别的排列。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= nums.length <= 14
 * 1 <= nums[i] <= 10^9
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
    int specialPerm(vector<int>& nums) {
        static const int mod = 1e9 + 7;
        int n = nums.size();
        vector<vector<int>> cache(1 << n, vector<int>(n, -1));
        int count = 0;
        function<int(int, int)> dfs = [&](int state, int back) -> int {
            if (cache[state][back] != -1) {
                return cache[state][back];
            }
            if (state == (1 << back)) {
                return 1;
            }
            cache[state][back] = 0;
            for (int i = 0; i < n; ++i) {
                if (i == back || !(state & (1 << i))) {
                    continue;
                }
                if (nums[i] % nums[back] != 0 && nums[back] % nums[i] != 0) {
                    continue;
                }
                cache[state][back] = (cache[state][back] + dfs(state ^ (1 << back), i)) % mod;
            }
            return cache[state][back];
        };
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = (ans + dfs((1 << n) - 1, i)) % mod;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,4,3]\n
// @lcpr case=end

 */

