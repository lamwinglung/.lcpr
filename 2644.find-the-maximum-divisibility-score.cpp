/*
 * @lc app=leetcode.cn id=2644 lang=cpp
 * @lcpr version=30202
 *
 * [2644] 找出可整除性得分最大的整数
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
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int result = INT_MAX;
        int maxCount = INT_MIN;

        for (auto div : divisors) {
            int count = 0;
            for (auto num : nums) {
                if (num % div == 0) {
                    ++count;
                }
            }
            if (count > maxCount) {
                maxCount = count;
                result = div;
            } else if (count == maxCount) {
                if (div < result) {
                    result = div;
                }
            }
        }

        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,7,9,3,9]\n[5,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [20,14,21,10]\n[5,7,5]\n
// @lcpr case=end

// @lcpr case=start
// [12]\n[10,16]\n
// @lcpr case=end

 */

