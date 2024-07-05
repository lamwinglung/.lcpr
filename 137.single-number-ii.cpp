/*
 * @lc app=leetcode.cn id=137 lang=cpp
 * @lcpr version=30202
 *
 * [137] 只出现一次的数字 II
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
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            int b = (1 << i);
            for (auto &num : nums) {
                sum += ((num & b) >> i);
            }
            ans |= ((sum % 3) << i);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,1,0,1,99]\n
// @lcpr case=end

// @lcpr case=start
// [99]\n
// @lcpr case=end

 */

