/*
 * @lc app=leetcode.cn id=67 lang=cpp
 * @lcpr version=30201
 *
 * [67] 二进制求和
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
    string addBinary(string a, string b) {
        string result;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = max(a.size(), b.size());
        int carry = 0;
        for (int i = 0; i < n; ++i) {
            if (i < a.size()) {
                carry += a[i] == '1' ? 1 : 0;
            }
            if (i < b.size()) {
                carry += b[i] == '1' ? 1 : 0;
            }
            result.push_back((carry & 1) ? '1' : '0');
            carry /= 2;
        }
        if (carry & 1) {
            result.push_back('1');
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "11"\n"1"\n
// @lcpr case=end

// @lcpr case=start
// "1010"\n"1011"\n
// @lcpr case=end

// @lcpr case=start
// "1"\n"1"\n
// @lcpr case=end

// @lcpr case=start
// "1000"\n"111"\n
// @lcpr case=end

 */

