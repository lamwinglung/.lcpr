/*
 * @lc app=leetcode.cn id=2981 lang=cpp
 * @lcpr version=30202
 *
 * [2981] 找出出现至少三次的最长特殊子字符串 I
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
    int maximumLength(string s) {
        int len = s.size();
        vector<int> chs[26];
        int cnt = 0;
        for (int i = 0; i < len; ++i) {
            ++cnt;
            if (i == len - 1 || s[i] != s[i + 1]) {
                int ch = s[i] - 'a';
                chs[ch].push_back(cnt);
                cnt = 0;

                for (int j = chs[ch].size() - 1; j > 0; --j) {
                    if (chs[ch][j] > chs[ch][j - 1]) {
                        swap(chs[ch][j], chs[ch][j - 1]);
                    } else {
                        break;
                    }
                }

                if (chs[ch].size() > 3) {
                    chs[ch].pop_back();
                }
            }
        }

        int ans = -1;
        for (int i = 0; i < 26; ++i) {
            if (chs[i].size() > 0 && chs[i][0] > 2) {
                ans = max(ans, chs[i][0] - 2);
            }
            if (chs[i].size() > 1 && chs[i][0] > 1) {
                ans = max(ans, min(chs[i][0] - 1, chs[i][1]));
            }
            if (chs[i].size() > 2) {
                ans = max(ans, chs[i][2]);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aaaa"\n
// @lcpr case=end

// @lcpr case=start
// "abcdef"\n
// @lcpr case=end

// @lcpr case=start
// "abcaba"\n
// @lcpr case=end

// @lcpr case=start
// "abcabba"\n
// @lcpr case=end

// @lcpr case=start
// "lkwwdddddnnnnnynnnnl"\n
// @lcpr case=end

 */
