/*
 * @lc app=leetcode.cn id=151 lang=cpp
 * @lcpr version=30202
 *
 * [151] 反转字符串中的单词
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
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int i = 0, start = 0, end = 0, n = s.size();
        while (start < n) {
            if (s[start] == ' ') {
                ++start;
                continue;
            }
            if (i != 0) {
                s[i++] = ' ';
            }
            end = start;
            while (end < n && s[end] != ' ') {
                s[i++] = s[end++];
            }
            reverse(s.begin() + i - end + start, s.begin() + i);
            start = end;
        }
        return s.substr(0, i);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "the sky is blue"\n
// @lcpr case=end

// @lcpr case=start
// "     hello a world     "\n
// @lcpr case=end

// @lcpr case=start
// "a good     example"\n
// @lcpr case=end

 */

