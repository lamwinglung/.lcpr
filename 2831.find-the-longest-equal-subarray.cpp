/*
 * @lc app=leetcode.cn id=2831 lang=cpp
 * @lcpr version=30202
 *
 * [2831] 找出最长等值子数组
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
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> table;
        for (int i = 0; i < nums.size(); ++i) {
            table[nums[i]].push_back(i);
        }
        int ans = 0;
        for (auto &[_, vec] : table) {
            for (int i = 0, j = 0; j < vec.size(); ++j) {
                while (i <= j && (vec[j] - vec[i] - j + i) > k) {
                    ++i;
                }
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2,3,1,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,2,1,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

