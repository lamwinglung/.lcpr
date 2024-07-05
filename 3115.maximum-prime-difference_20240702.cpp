/*
 * @lc app=leetcode.cn id=3115 lang=cpp
 * @lcpr version=30204
 *
 * [3115] 质数的最大距离
 *
 * https://leetcode.cn/problems/maximum-prime-difference/description/
 *
 * algorithms
 * Medium (58.70%)
 * Likes:    11
 * Dislikes: 0
 * Total Accepted:    11K
 * Total Submissions: 17.5K
 * Testcase Example:  '[4,2,9,5,3]'
 *
 * 给你一个整数数组 nums。
 * 
 * 返回两个（不一定不同的）质数在 nums 中 下标 的 最大距离。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： nums = [4,2,9,5,3]
 * 
 * 输出： 3
 * 
 * 解释： nums[1]、nums[3] 和 nums[4] 是质数。因此答案是 |4 - 1| = 3。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： nums = [4,8,2,8]
 * 
 * 输出： 0
 * 
 * 解释： nums[2] 是质数。因为只有一个质数，所以答案是 |2 - 2| = 0。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 3 * 10^5
 * 1 <= nums[i] <= 100
 * 输入保证 nums 中至少有一个质数。
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
    int maximumPrimeDifference(vector<int>& nums) {
        unordered_set<int> primes = {
            2, 3, 5, 7, 11,
            13, 17, 19, 23, 29,
            31, 37, 41, 43, 47,
            53, 59, 61, 67, 71,
            73, 79, 83, 89, 97
        };

        int first = 0;
        while (first < nums.size() && primes.count(nums[first]) == 0) {
            ++first;
        }
        int end = nums.size() - 1;
        while (end >= 0 && primes.count(nums[end]) == 0) {
            --end;
        }
        return end - first;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,9,5,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,8,2,8]\n
// @lcpr case=end

 */

