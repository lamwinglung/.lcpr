/*
 * @lc app=leetcode.cn id=2982 lang=cpp
 * @lcpr version=30202
 *
 * [2982] 找出出现至少三次的最长特殊子字符串 II
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
        int cnt = 0;
        vector<vector<int>> cnts(26);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            ++cnt;
            if (i == n - 1 || s[i] != s[i + 1]) {
                int ci = s[i] - 'a';
                cnts[ci].push_back(cnt);
                cnt = 0;
                for (int j = cnts[ci].size() - 1; j > 0; --j) {
                    if (cnts[ci][j] > cnts[ci][j - 1]) {
                        swap(cnts[ci][j], cnts[ci][j - 1]);
                    } else {
                        break;
                    }
                }
                if (cnts[ci].size() > 3) {
                    cnts[ci].pop_back();
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < 26; ++i) {
            if (cnts[i].size() > 0 && cnts[i][0] > 2) {
                ans = max(ans, cnts[i][0] - 2);
            }
            if (cnts[i].size() > 1 && cnts[i][0] > 1) {
                ans = max(ans, min(cnts[i][0] - 1, cnts[i][1]));
            }
            if (cnts[i].size() > 2) {
                ans = max(ans, cnts[i][2]);
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

 */

