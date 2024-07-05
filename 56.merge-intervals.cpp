/*
 * @lc app=leetcode.cn id=56 lang=cpp
 * @lcpr version=30201
 *
 * [56] 合并区间
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto &left, const auto &right) {
            if (left[0] != right[0]) {
                return left[0] < right[0];
            }
            return left[1] < right[1];
        });

        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for (auto &interval : intervals) {
            int l = interval[0], r = interval[1];
            if (l > result.back()[1]) {
                result.push_back({l, r});
            } else {
                result.back()[1] = max(result.back()[1], r);
            }
        }

        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[2,6],[8,10],[10,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[3,3],[10,10],[10,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,7],[5,6],[10,10],[10,18],[18,18]]\n
// @lcpr case=end

 */

