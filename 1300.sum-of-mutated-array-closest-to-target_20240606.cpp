/*
 * @lc app=leetcode.cn id=1300 lang=cpp
 * @lcpr version=30203
 *
 * [1300] 转变数组后最接近目标值的数组和
 *
 * https://leetcode.cn/problems/sum-of-mutated-array-closest-to-target/description/
 *
 * algorithms
 * Medium (46.90%)
 * Likes:    208
 * Dislikes: 0
 * Total Accepted:    32.7K
 * Total Submissions: 69.8K
 * Testcase Example:  '[4,9,3]\n10'
 *
 * 给你一个整数数组 arr 和一个目标值 target ，请你返回一个整数 value ，使得将数组中所有大于 value 的值变成 value
 * 后，数组的和最接近  target （最接近表示两者之差的绝对值最小）。
 * 
 * 如果有多种使得和最接近 target 的方案，请你返回这些整数中的最小值。
 * 
 * 请注意，答案不一定是 arr 中的数字。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [4,9,3], target = 10
 * 输出：3
 * 解释：当选择 value 为 3 时，数组会变成 [3, 3, 3]，和为 9 ，这是最接近 target 的方案。
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = [2,3,5], target = 10
 * 输出：5
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr = [60864,25176,27249,21296,20204], target = 56803
 * 输出：11361
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 10^4
 * 1 <= arr[i], target <= 10^5
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
    

    int findBestValue(vector<int>& arr, int target) {

    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,9,3]\n10\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n10\n
// @lcpr case=end

// @lcpr case=start
// [60864,25176,27249,21296,20204]\n56803\n
// @lcpr case=end

 */

