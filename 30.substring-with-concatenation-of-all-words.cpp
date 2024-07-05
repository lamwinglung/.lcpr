/*
 * @lc app=leetcode.cn id=30 lang=cpp
 * @lcpr version=30201
 *
 * [30] 串联所有单词的子串
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
    vector<int> findSubstring(string s, vector<string>& words) {
        int m = words.size();
        int n = words[0].size();
        int sz = s.size();
        vector<int> result;
        for (int i = 0; i < n && (m * n + i) <= sz; ++i) {
            unordered_map<string, int> differ;
            for (auto &word : words) {
                --differ[word];
            }
            for (int start = i; start < sz - (m * n) + 1; start += n) {
                if (start == i) {
                    for (int j = 0; j < m; ++j) {
                        string newWord = s.substr(start + (j * n), n);
                        if (++differ[newWord] == 0) {
                            differ.erase(newWord);
                        }
                    }
                } else {
                    string newWord = s.substr(start + (m * n) - n, n);
                    if (++differ[newWord] == 0) {
                        differ.erase(newWord);
                    }
                    string removeWord = s.substr(start - n, n);
                    if (--differ[removeWord] == 0) {
                        differ.erase(removeWord);
                    }
                }
                if (differ.empty()) {
                    result.push_back(start);
                }
            }
        }
        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "barfoothefoobarman"\n["foo","bar"]\n
// @lcpr case=end

// @lcpr case=start
// "wordgoodgoodgoodbestword"\n["word","good","best","word"]\n
// @lcpr case=end

// @lcpr case=start
// "barfoofoobarthefoobarman"\n["bar","foo","the"]\n
// @lcpr case=end

// @lcpr case=start
// "a"\n["a"]\n
// @lcpr case=end

// @lcpr case=start
// "abcdef"\n["abc","def"]\n
// @lcpr case=end

 */

