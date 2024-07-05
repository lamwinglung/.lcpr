/*
 * @lc app=leetcode.cn id=1864 lang=cpp
 * @lcpr version=30203
 *
 * [1864] 构成交替字符串需要的最小交换次数
 *
 * https://leetcode.cn/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/description/
 *
 * algorithms
 * Medium (41.55%)
 * Likes:    37
 * Dislikes: 0
 * Total Accepted:    8.6K
 * Total Submissions: 20.6K
 * Testcase Example:  '"111000"'
 *
 * 给你一个二进制字符串 s ，现需要将其转化为一个 交替字符串 。请你计算并返回转化所需的 最小 字符交换次数，如果无法完成转化，返回 -1 。
 * 
 * 交替字符串 是指：相邻字符之间不存在相等情况的字符串。例如，字符串 "010" 和 "1010" 属于交替字符串，但 "0100" 不是。
 * 
 * 任意两个字符都可以进行交换，不必相邻 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "111000"
 * 输出：1
 * 解释：交换位置 1 和 4："111000" -> "101010" ，字符串变为交替字符串。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "010"
 * 输出：0
 * 解释：字符串已经是交替字符串了，不需要交换。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "1110"
 * 输出：-1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s[i] 的值为 '0' 或 '1'
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
    int minSwaps(string s) {
        int n = s.size();
        int c0 = count(s.begin(), s.end(), '0');
        int c1 = s.size() - c0;

        if (abs(c0 - c1) > 1) {
            return -1;
        }

        int ans = INT_MAX;
        if (c1 - c0 >= 0) {
            int diff = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] - '0' != (i + 1) % 2) {
                    ++diff;
                }
            }
            ans = min(ans, diff / 2);
        }
        if (c0 - c1 >= 0) {
            int diff = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] - '0' != i % 2) {
                    ++diff;
                }
            }
            ans = min(ans, diff / 2);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "111000"\n
// @lcpr case=end

// @lcpr case=start
// "010"\n
// @lcpr case=end

// @lcpr case=start
// "1110"\n
// @lcpr case=end

 */

