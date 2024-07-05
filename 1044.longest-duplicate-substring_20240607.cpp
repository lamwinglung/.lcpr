/*
 * @lc app=leetcode.cn id=1044 lang=cpp
 * @lcpr version=30203
 *
 * [1044] 最长重复子串
 *
 * https://leetcode.cn/problems/longest-duplicate-substring/description/
 *
 * algorithms
 * Hard (35.30%)
 * Likes:    404
 * Dislikes: 0
 * Total Accepted:    31.6K
 * Total Submissions: 89.7K
 * Testcase Example:  '"banana"'
 *
 * 给你一个字符串 s ，考虑其所有 重复子串 ：即 s 的（连续）子串，在 s 中出现 2 次或更多次。这些出现之间可能存在重叠。
 * 
 * 返回 任意一个 可能具有最长长度的重复子串。如果 s 不含重复子串，那么答案为 "" 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "banana"
 * 输出："ana"
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "abcd"
 * 输出：""
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= s.length <= 3 * 10^4
 * s 由小写英文字母组成
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
    long long pow(int a, int m, int mod) {
        int ans = 1;
        int contribute = a;

        while (m > 0) {
            if (m % 2 == 1) {
                ans = ans * contribute % mod;
            }
            contribute = contribute * contribute % mod;
            m /= 2;
        }
        return ans;
    }

    string longestDupSubstring(string s) {
        int n = s.size();
        vector<>
    }
};
// @lc code=end



/*
// @lcpr case=start
// "banana"\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n
// @lcpr case=end

 */

