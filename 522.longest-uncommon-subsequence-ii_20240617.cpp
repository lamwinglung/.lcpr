/*
 * @lc app=leetcode.cn id=522 lang=cpp
 * @lcpr version=30203
 *
 * [522] 最长特殊序列 II
 *
 * https://leetcode.cn/problems/longest-uncommon-subsequence-ii/description/
 *
 * algorithms
 * Medium (48.86%)
 * Likes:    225
 * Dislikes: 0
 * Total Accepted:    43.7K
 * Total Submissions: 86.4K
 * Testcase Example:  '["aba","cdc","eae"]'
 *
 * 给定字符串列表 strs ，返回其中 最长的特殊序列 的长度。如果最长特殊序列不存在，返回 -1 。
 * 
 * 特殊序列 定义如下：该序列为某字符串 独有的子序列（即不能是其他字符串的子序列）。
 * 
 * s 的 子序列可以通过删去字符串 s 中的某些字符实现。
 * 
 * 
 * 例如，"abc" 是 "aebdc" 的子序列，因为您可以删除"aebdc"中的下划线字符来得到 "abc"
 * 。"aebdc"的子序列还包括"aebdc"、 "aeb" 和 "" (空字符串)。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: strs = ["aba","cdc","eae"]
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: strs = ["aaa","aaa","aa"]
 * 输出: -1
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 2 <= strs.length <= 50
 * 1 <= strs[i].length <= 10
 * strs[i] 只包含小写英文字母
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
    int findLUSlength(vector<string>& strs) {

    }
};
// @lc code=end



/*
// @lcpr case=start
// ["aba","cdc","eae"]\n
// @lcpr case=end

// @lcpr case=start
// ["aaa","aaa","aa"]\n
// @lcpr case=end

 */

