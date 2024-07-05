/*
 * @lc app=leetcode.cn id=205 lang=cpp
 * @lcpr version=30202
 *
 * [205] 同构字符串
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
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, char> s2t, t2s;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            char x = s[i], y = t[i];
            if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x)) {
                return false;
            }
            s2t[x] = y;
            t2s[y] = x;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "egg"\n"add"\n
// @lcpr case=end

// @lcpr case=start
// "foo"\n"bar"\n
// @lcpr case=end

// @lcpr case=start
// "paper"\n"title"\n
// @lcpr case=end

// @lcpr case=start
// "badc"\n"baba"\n
// @lcpr case=end

 */

