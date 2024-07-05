/*
 * @lc app=leetcode.cn id=1553 lang=cpp
 * @lcpr version=30201
 *
 * [1553] 吃掉 N 个橘子的最少天数
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
    unordered_map<int, int> dp;

    int inner(int n) {
        if (dp.find(n) != dp.end()) {
            return dp[n];
        }

        int result = INT_MAX;
        if (n % 3 == 0) {
            result = min(result, inner(n / 3) + 1);
        }
        if (n % 2 == 0) {
            result = min(result, inner(n / 2) + 1);
        }
        if (n % 2 != 0 || n % 3 != 0) {
            result = min(result, inner(n - 1) + 1);
        }
        dp[n] = result;
        return result;
    }

    int minDays(int n) {
        dp[0] = 0;
        dp[1] = 1;

        return inner(n);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 6\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 56\n
// @lcpr case=end

// @lcpr case=start
// 2000000000\n
// @lcpr case=end

 */

