/*
 * @lc app=leetcode.cn id=2663 lang=cpp
 * @lcpr version=30203
 *
 * [2663] 字典序最小的美丽字符串
 *
 * https://leetcode.cn/problems/lexicographically-smallest-beautiful-string/description/
 *
 * algorithms
 * Hard (44.96%)
 * Likes:    40
 * Dislikes: 0
 * Total Accepted:    9.7K
 * Total Submissions: 15.9K
 * Testcase Example:  '"abcz"\n26'
 *
 * 如果一个字符串满足以下条件，则称其为 美丽字符串 ：
 * 
 * 
 * 它由英语小写字母表的前 k 个字母组成。
 * 它不包含任何长度为 2 或更长的回文子字符串。
 * 
 * 
 * 给你一个长度为 n 的美丽字符串 s 和一个正整数 k 。
 * 
 * 请你找出并返回一个长度为 n 的美丽字符串，该字符串还满足：在字典序大于 s
 * 的所有美丽字符串中字典序最小。如果不存在这样的字符串，则返回一个空字符串。
 * 
 * 对于长度相同的两个字符串 a 和 b ，如果字符串 a 在与字符串 b 不同的第一个位置上的字符字典序更大，则字符串 a 的字典序大于字符串 b
 * 。
 * 
 * 
 * 例如，"abcd" 的字典序比 "abcc" 更大，因为在不同的第一个位置（第四个字符）上 d 的字典序大于 c 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "abcz", k = 26
 * 输出："abda"
 * 解释：字符串 "abda" 既是美丽字符串，又满足字典序大于 "abcz" 。
 * 可以证明不存在字符串同时满足字典序大于 "abcz"、美丽字符串、字典序小于 "abda" 这三个条件。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "dc", k = 4
 * 输出：""
 * 解释：可以证明，不存在既是美丽字符串，又字典序大于 "dc" 的字符串。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n == s.length <= 10^5
 * 4 <= k <= 26
 * s 是一个美丽字符串
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
    string smallestBeautifulString(string s, int k) {
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcz"\n26\n
// @lcpr case=end

// @lcpr case=start
// "dc"\n4\n
// @lcpr case=end

 */

