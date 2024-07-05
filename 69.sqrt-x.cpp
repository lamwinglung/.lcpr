/*
 * @lc app=leetcode.cn id=69 lang=cpp
 * @lcpr version=30201
 *
 * [69] x 的平方根 
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
    int mySqrt(int x) {
        if (x == 1) {
            return 1;
        }

        long l = 0;
        long r = x / 2;
        while (l <= r) {
            long mid = (l + r) / 2;
            long base = mid * mid;
            long above = (mid + 1) * (mid + 1);
            if (base <= x && above > x) {
                return mid;
            }
            if (base > x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 2147483647\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */

