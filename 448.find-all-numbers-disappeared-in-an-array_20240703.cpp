/*
 * @lc app=leetcode.cn id=448 lang=cpp
 * @lcpr version=30204
 *
 * [448] 找到所有数组中消失的数字
 *
 * https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (65.82%)
 * Likes:    1325
 * Dislikes: 0
 * Total Accepted:    320.2K
 * Total Submissions: 486K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * 给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。请你找出所有在 [1, n] 范围内但没有出现在 nums
 * 中的数字，并以数组的形式返回结果。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [4,3,2,7,8,2,3,1]
 * 输出：[5,6]
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,1]
 * 输出：[2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 <= n <= 10^5
 * 1 <= nums[i] <= n
 * 
 * 
 * 进阶：你能在不使用额外空间且时间复杂度为 O(n) 的情况下解决这个问题吗? 你可以假定返回的数组不算在额外空间内。
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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (auto &num : nums) {
            int i = (num - 1) % n;
            nums[i] += n;
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= n) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,3,2,7,8,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */

