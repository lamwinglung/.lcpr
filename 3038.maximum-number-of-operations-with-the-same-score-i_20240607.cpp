/*
 * @lc app=leetcode.cn id=3038 lang=cpp
 * @lcpr version=30203
 *
 * [3038] 相同分数的最大操作数目 I
 *
 * https://leetcode.cn/problems/maximum-number-of-operations-with-the-same-score-i/description/
 *
 * algorithms
 * Easy (66.56%)
 * Likes:    8
 * Dislikes: 0
 * Total Accepted:    8K
 * Total Submissions: 11.5K
 * Testcase Example:  '[3,2,1,4,5]'
 *
 * 给你一个整数数组 nums ，如果 nums 至少 包含 2 个元素，你可以执行以下操作：
 * 
 * 
 * 选择 nums 中的前两个元素并将它们删除。
 * 
 * 
 * 一次操作的 分数 是被删除元素的和。
 * 
 * 在确保 所有操作分数相同 的前提下，请你求出 最多 能进行多少次操作。
 * 
 * 请你返回按照上述要求 最多 可以进行的操作次数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [3,2,1,4,5]
 * 输出：2
 * 解释：我们执行以下操作：
 * - 删除前两个元素，分数为 3 + 2 = 5 ，nums = [1,4,5] 。
 * - 删除前两个元素，分数为 1 + 4 = 5 ，nums = [5] 。
 * 由于只剩下 1 个元素，我们无法继续进行任何操作。
 * 
 * 示例 2：
 * 
 * 输入：nums = [3,2,6,1,4]
 * 输出：1
 * 解释：我们执行以下操作：
 * - 删除前两个元素，分数为 3 + 2 = 5 ，nums = [6,1,4] 。
 * 由于下一次操作的分数与前一次不相等，我们无法继续进行任何操作。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= nums.length <= 100
 * 1 <= nums[i] <= 1000
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
    int maxOperations(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int sum = nums[0] + nums[1];
        int count = 1;
        for (int i = 2; i + 1 < nums.size(); i += 2) {
            if (nums[i] + nums[i + 1] == sum) {
                ++count;
            } else {
                break;
            }
        }
        return count;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,1,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,6,1,4]\n
// @lcpr case=end

 */

