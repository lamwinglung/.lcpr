/*
 * @lc app=leetcode.cn id=2522 lang=cpp
 * @lcpr version=30203
 *
 * [2522] 将字符串分割成值不超过 K 的子字符串
 *
 * https://leetcode.cn/problems/partition-string-into-substrings-with-values-at-most-k/description/
 *
 * algorithms
 * Medium (49.71%)
 * Likes:    13
 * Dislikes: 0
 * Total Accepted:    7.3K
 * Total Submissions: 14.6K
 * Testcase Example:  '"165462"\n60'
 *
 * 给你一个字符串 s ，它每一位都是 1 到 9 之间的数字组成，同时给你一个整数 k 。
 * 
 * 如果一个字符串 s 的分割满足以下条件，我们称它是一个 好 分割：
 * 
 * 
 * s 中每个数位 恰好 属于一个子字符串。
 * 每个子字符串的值都小于等于 k 。
 * 
 * 
 * 请你返回 s 所有的 好 分割中，子字符串的 最少 数目。如果不存在 s 的 好 分割，返回 -1 。
 * 
 * 注意：
 * 
 * 
 * 一个字符串的 值 是这个字符串对应的整数。比方说，"123" 的值为 123 ，"1" 的值是 1 。
 * 子字符串 是字符串中一段连续的字符序列。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "165462", k = 60
 * 输出：4
 * 解释：我们将字符串分割成子字符串 "16" ，"54" ，"6" 和 "2" 。每个子字符串的值都小于等于 k = 60 。
 * 不存在小于 4 个子字符串的好分割。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "238182", k = 5
 * 输出：-1
 * 解释：这个字符串不存在好分割。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] 是 '1' 到 '9' 之间的数字。
 * 1 <= k <= 10^9
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
    int minimumPartition(string s, int k) {
        long long a = 0;
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            int c= s[i] - '0';
            if (c > k) {
                return -1;
            }
            a = a * 10 + c;
            if (a > k) {
                count += 1;
                a = c;
            }
        }
        return count + 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "165461"\n61\n
// @lcpr case=end

// @lcpr case=start
// "238182"\n5\n
// @lcpr case=end

 */

