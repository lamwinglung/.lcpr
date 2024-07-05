/*
 * @lc app=leetcode.cn id=2589 lang=cpp
 * @lcpr version=30202
 *
 * [2589] 完成所有任务的最少时间
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
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const auto &left, const auto &right) {
            return left[1] < right[1];
        });

        vector<int> run(tasks.back()[1] + 1);

        int result = 0;
        for (auto &task : tasks) {
            int start = task[0], end = task[1], duration = task[2];
            duration -= accumulate(run.begin() + start, run.begin() + end + 1, 0);
            if (duration < 0) {
                duration = 0;
            }
            result += duration;
            for (int j = end; j >= 0 && duration > 0; --j) {
                if (run[j] == 0) {
                    run[j] = 1;
                    --duration;
                }
            }
        }

        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,3,1],[4,5,1],[1,5,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,2],[2,5,3],[5,6,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,3],[2,4,3]]\n
// @lcpr case=end

 */

