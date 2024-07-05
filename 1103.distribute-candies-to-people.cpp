/*
 * @lc app=leetcode.cn id=1103 lang=cpp
 * @lcpr version=30202
 *
 * [1103] 分糖果 II
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
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int i = 0, cur = 0;
        while (candies > 0) {
            ++cur;
            ans[i] += min(candies, cur);
            candies -= cur;
            i = (i + 1) % ans.size();
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n4\n
// @lcpr case=end

// @lcpr case=start
// 10\n3\n
// @lcpr case=end

 */

