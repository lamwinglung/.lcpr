/*
 * @lc app=leetcode.cn id=290 lang=cpp
 * @lcpr version=30202
 *
 * [290] 单词规律
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
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;

        vector<string> words;
        for (int start = 0; start < s.size();) {
            int end = s.find_first_of(' ', start);
            if (end == string::npos) {
                end = s.size();
            }
            if (start < end) {
                words.emplace_back(s.substr(start, end - start));
            }
            start = end + 1;
        }

        if (words.size() != pattern.size()) {
            return false;
        }

        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            string &word = words[i];
            if ((p2s.count(c) && p2s[c] != word) || (s2p.count(word) && s2p[word] != c)) {
                return false;
            }
            p2s[c] = word;
            s2p[word] = c;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abba"\n"dog cat cat dog"\n
// @lcpr case=end

// @lcpr case=start
// "abba"\n"dog cat cat fish"\n
// @lcpr case=end

// @lcpr case=start
// "aaaa"\n"dog cat cat dog"\n
// @lcpr case=end

 */

