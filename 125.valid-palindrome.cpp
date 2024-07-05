/*
 * @lc app=leetcode.cn id=125 lang=cpp
 * @lcpr version=30201
 *
 * [125] 验证回文串
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
    bool isPalindrome(string s) {
        string pali;
        for (char c : s) {
            if (isalnum(c)) {
                pali.push_back(tolower(c));
            }
        }

        for (int i = 0; i < pali.size() / 2; ++i) {
            if (pali[i] != pali[pali.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "A man, a plan, a canal: Panama"\n
// @lcpr case=end

// @lcpr case=start
// "race a car"\n
// @lcpr case=end

// @lcpr case=start
// " "\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

 */

