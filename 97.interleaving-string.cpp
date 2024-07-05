/*
 * @lc app=leetcode.cn id=97 lang=cpp
 * @lcpr version=30202
 *
 * [97] 交错字符串
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
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) {
            return false;
        }
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                int p = i + j -1;
                if (i > 0) {
                    dp[i][j] = dp[i][j] || (s1[i - 1] == s3[p] && dp[i - 1][j]);
                }
                if (j > 0) {
                    dp[i][j] = dp[i][j] || (s2[j - 1] == s3[p] && dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aabcc"\n"dbbca"\n"aadbbcbcac"\n
// @lcpr case=end

// @lcpr case=start
// "aabcc"\n"dbbca"\n"aadbbbaccc"\n
// @lcpr case=end

// @lcpr case=start
// ""\n""\n""\n
// @lcpr case=end

// @lcpr case=start
// "a"\n""\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "aacaac"\n"aacaaeaac"\n"aacaaeaaeaacaac"\n
// @lcpr case=end


 */

