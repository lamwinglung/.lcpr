/*
 * @lc app=leetcode.cn id=2903 lang=cpp
 * @lcpr version=30202
 *
 * [2903] 找出满足差值条件的下标 I
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
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int minIndex = 0, maxIndex = 0;
        for (int j = indexDifference; j < nums.size(); ++j) {
            int i = j - indexDifference;
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
            if (abs(nums[minIndex] - nums[j]) >= valueDifference) {
                return {minIndex, j};
            }
            if (abs(nums[maxIndex] - nums[j]) >= valueDifference) {
                return {maxIndex, j};
            }
        }
        return {-1, -1};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,1,4,1]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n0\n0\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n2\n4\n
// @lcpr case=end

 */

