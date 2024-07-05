/*
 * @lc app=leetcode.cn id=2928 lang=cpp
 * @lcpr version=30202
 *
 * [2928] 给小朋友们分糖果 I
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
    int distributeCandies(int n, int limit) {
        int count = 0;
        function<void(int, int, int)> backtrace = [&](int n, int limit, int deep) {
            if (deep == 2) {
                if (n <= limit) {
                    count += 1;
                }
                return;
            }
            for (int i = 0; i <= min(n, limit); ++i) {
                backtrace(n - i, limit, deep + 1);
            }
        };
        backtrace(n, limit, 0);
        return count;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n2\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n
// @lcpr case=end

// @lcpr case=start
// 10\n3\n
// @lcpr case=end

// @lcpr case=start
// 1\n10\n
// @lcpr case=end

 */

