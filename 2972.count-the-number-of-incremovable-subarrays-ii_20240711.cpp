/*
 * @lc app=leetcode.cn id=2972 lang=cpp
 * @lcpr version=30204
 *
 * [2972] 统计移除递增子数组的数目 II
 *
 * https://leetcode.cn/problems/count-the-number-of-incremovable-subarrays-ii/description/
 *
 * algorithms
 * Hard (53.11%)
 * Likes:    33
 * Dislikes: 0
 * Total Accepted:    7.8K
 * Total Submissions: 12.3K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个下标从 0 开始的 正 整数数组 nums 。
 * 
 * 如果 nums 的一个子数组满足：移除这个子数组后剩余元素 严格递增 ，那么我们称这个子数组为 移除递增 子数组。比方说，[5, 3, 4, 6, 7]
 * 中的 [3, 4] 是一个移除递增子数组，因为移除该子数组后，[5, 3, 4, 6, 7] 变为 [5, 6, 7] ，是严格递增的。
 * 
 * 请你返回 nums 中 移除递增 子数组的总数目。
 * 
 * 注意 ，剩余元素为空的数组也视为是递增的。
 * 
 * 子数组 指的是一个数组中一段连续的元素序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,2,3,4]
 * 输出：10
 * 解释：10 个移除递增子数组分别为：[1], [2], [3], [4], [1,2], [2,3], [3,4], [1,2,3], [2,3,4]
 * 和 [1,2,3,4]。移除任意一个子数组后，剩余元素都是递增的。注意，空数组不是移除递增子数组。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [6,5,7,8]
 * 输出：7
 * 解释：7 个移除递增子数组分别为：[5], [6], [5,7], [6,5], [5,7,8], [6,5,7] 和 [6,5,7,8] 。
 * nums 中只有这 7 个移除递增子数组。
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [8,7,6,6]
 * 输出：3
 * 解释：3 个移除递增子数组分别为：[8,7,6], [7,6,6] 和 [8,7,6,6] 。注意 [8,7] 不是移除递增子数组因为移除 [8,7]
 * 后 nums 变为 [6,6] ，它不是严格递增的。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
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
    long long incremovableSubarrayCount(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int l = 1;
        while (l < n && nums[l - 1] < nums[l]) {
            ++l;
        }
        if (l == n) {
            return 1LL * (n + 1) * n / 2;
        }
        l = l - 1;
        ans += (l + 2);
        for (int r = n - 1; r >= 1; --r) {
            if (r < n - 1 && nums[r] >= nums[r + 1]) {
                break;
            }
            while (l >= 0 && nums[l] >= nums[r]) {
                --l;
            }
            ans += (l + 2);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [6,5,7,8]\n
// @lcpr case=end

// @lcpr case=start
// [8,7,6,6]\n
// @lcpr case=end

 */

