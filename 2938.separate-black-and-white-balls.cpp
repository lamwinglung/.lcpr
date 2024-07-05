/*
 * @lc app=leetcode.cn id=2938 lang=cpp
 * @lcpr version=30203
 *
 * [2938] 区分黑球与白球
 *
 * https://leetcode.cn/problems/separate-black-and-white-balls/description/
 *
 * algorithms
 * Medium (54.34%)
 * Likes:    21
 * Dislikes: 0
 * Total Accepted:    10.5K
 * Total Submissions: 17K
 * Testcase Example:  '"101"'
 *
 * 桌子上有 n 个球，每个球的颜色不是黑色，就是白色。
 * 
 * 给你一个长度为 n 、下标从 0 开始的二进制字符串 s，其中 1 和 0 分别代表黑色和白色的球。
 * 
 * 在每一步中，你可以选择两个相邻的球并交换它们。
 * 
 * 返回「将所有黑色球都移到右侧，所有白色球都移到左侧所需的 最小步数」。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "101"
 * 输出：1
 * 解释：我们可以按以下方式将所有黑色球移到右侧：
 * - 交换 s[0] 和 s[1]，s = "011"。
 * 最开始，1 没有都在右侧，需要至少 1 步将其移到右侧。
 * 
 * 示例 2：
 * 
 * 输入：s = "100"
 * 输出：2
 * 解释：我们可以按以下方式将所有黑色球移到右侧：
 * - 交换 s[0] 和 s[1]，s = "010"。
 * - 交换 s[1] 和 s[2]，s = "001"。
 * 可以证明所需的最小步数为 2 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "0111"
 * 输出：0
 * 解释：所有黑色球都已经在右侧。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n == s.length <= 10^5
 * s[i] 不是 '0'，就是 '1'。
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
    long long minimumSteps(string s) {
        int count = 0;
        long long ans = 0;
        for (auto &c : s) {
            if (c == '1') {
                ++count;
            } else {
                ans += count;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "101"\n
// @lcpr case=end

// @lcpr case=start
// "100"\n
// @lcpr case=end

// @lcpr case=start
// "0111"\n
// @lcpr case=end

// @lcpr case=start
// "0111011110100011"\n
// @lcpr case=end


// @lcpr case=start
// "01110111101000110111011110100011"\n
// @lcpr case=end


// @lcpr case=start
// "1"\n
// @lcpr case=end

// @lcpr case=start
// "0"\n
// @lcpr case=end

// @lcpr case=start
// "000000000000"\n
// @lcpr case=end

// @lcpr case=start
// "111111111111111"\n
// @lcpr case=end

 */

