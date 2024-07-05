/*
 * @lc app=leetcode.cn id=1673 lang=cpp
 * @lcpr version=30202
 *
 * [1673] 找出最具竞争力的子序列
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
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (!res.empty() && (n - i) > (k - (int)res.size()) && nums[i] < res.back()) {
                res.pop_back();
            }
            res.push_back(nums[i]);
        }
        res.resize(k);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,2,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,4,3,3,5,4,9,6]\n4\n
// @lcpr case=end

// @lcpr case=start
// [7,6,5,4,3,2,1]\n4\n
// @lcpr case=end

// @lcpr case=start
// [71,18,52,29,55,73,24,42,66,8,80,2]\n3\n
// @lcpr case=end

 */

