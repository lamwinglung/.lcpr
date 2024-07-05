/*
 * @lc app=leetcode.cn id=826 lang=cpp
 * @lcpr version=30202
 *
 * [826] 安排工作以达到最大收益
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
    struct Work {
        int difficulty;
        int profit;
    };

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& workers) {
        int n = difficulty.size();
        vector<Work> works;
        for (int i = 0; i < n; ++i) {
            works.emplace_back(difficulty[i], profit[i]);
        }
        sort(works.begin(), works.end(), [](auto &left, auto &right) {
            return left.difficulty < right.difficulty;
        });

        int maxProfit = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (works[i].profit > maxProfit) {
                maxProfit = works[i].profit;
            } else {
                works[i].profit = maxProfit;
            }
        }

        auto findMaxProfit = [&](int num) -> int {
            int left = 0, right = n - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (works[mid].difficulty <= num) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return right < 0 ? 0 : works[right].profit;
        };

        int sum = 0;
        for (auto worder : workers) {
            sum += findMaxProfit(worder);
        }
        return sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,4,6,8,10]\n[10,20,30,40,50]\n[1,4,5,6,7]\n
// @lcpr case=end

// @lcpr case=start
// [2]\n[10]\n[1,2,3,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [85,47,57]\n[24,66,99]\n[40,25,25]\n
// @lcpr case=end

 */

