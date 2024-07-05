/*
 * @lc app=leetcode.cn id=134 lang=cpp
 * @lcpr version=30202
 *
 * [134] 加油站
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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_sum = accumulate(gas.begin(), gas.end(), 0);
        int cost_sum = accumulate(cost.begin(), cost.end(), 0);
        if (gas_sum < cost_sum) {
            return -1;
        }

        int n = gas.size();
        vector<int> remain(2 * n);
        for (int i = 0; i < n; ++i) {
            remain[i] = remain[i + n] = gas[i] - cost[i];
        }
        int start = 0, sum = remain[0], max_sum = remain[0];
        for (int i = 1; i < remain.size(); ++i) {
            if (sum < 0) {
                sum = remain[i];
                start = i;
            } else {
                sum += remain[i];
                max_sum = max(max_sum, sum);
            }
        }
        return start;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n[3,4,5,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n[3,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,2,3,4]\n[3,4,5,1,2,3,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,1,1,1]\n[1,2,2,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n[1]\n
// @lcpr case=end

 */

