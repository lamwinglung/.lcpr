/*
 * @lc app=leetcode.cn id=1010 lang=cpp
 * @lcpr version=30203
 *
 * [1010] 总持续时间可被 60 整除的歌曲
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
    int numPairsDivisibleBy60(vector<int>& time) {

        unordered_map<int,int> mp;
        for (int i = 0; i <= 60; ++i) {
            mp[i] = 0;
        }
        int count = 0;
        for (int i = 0; i < time.size(); ++i) {
            int remain = time[i] % 60;
            count += (mp[60 - remain]);
            mp[remain == 0 ? 60 : remain] += 1;
        }
        return count;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [30,20,150,100,40]\n
// @lcpr case=end

// @lcpr case=start
// [60,60,60]\n
// @lcpr case=end

 */

