/*
 * @lc app=leetcode.cn id=66 lang=cpp
 * @lcpr version=30201
 *
 * [66] 加一
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
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int n = digits.size();
        int plus = 1;
        for (int i = 0; i < n; ++i) {
            int newDigit = digits[i] + plus;
            digits[i] = newDigit % 10;
            plus = newDigit / 10;
            if (plus == 0) {
                break;
            }
        }
        if (plus != 0) {
            digits.push_back(plus);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

// @lcpr case=start
// [9]\n
// @lcpr case=end

 */

