/*
 * @lc app=leetcode.cn id=228 lang=cpp
 * @lcpr version=30202
 *
 * [228] 汇总区间
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
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int start = 0, end = 0;
        for (int start = 0, end = 0; end < nums.size(); ++end) {
            if (end == nums.size() - 1 || nums[end] + 1 != nums[end + 1]) {
                if (start == end) {
                    ans.push_back(to_string(nums[start]));
                } else {
                    ans.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
                }
                start = end + 1;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,2,4,5,7]\n
// @lcpr case=end

// @lcpr case=start
// [0,2,3,4,6,8,9]\n
// @lcpr case=end

// @lcpr case=start
// [0,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end


 */

