/*
 * @lc app=leetcode.cn id=2028 lang=cpp
 * @lcpr version=30202
 *
 * [2028] 找出缺失的观测数据
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
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int mSum = accumulate(rolls.begin(), rolls.end(), 0);
        int sum = mean * (m + n);
        int nSum = sum - mSum;
        if (nSum < n || nSum > n * 6) {
            return {};
        }
        vector<int> result(n, nSum / n);
        int remain = nSum % n;
        for (int i = 0; i < n; ++i) {
            int add = 6 - result[i];
            if (add > remain) {
                add = remain;
            }
            result[i] += add;
            remain -= add;
            if (remain <= 0) {
                break;
            }
        }
        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,4,3]\n4\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,5,6]\n3\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n6\n4\n
// @lcpr case=end

// @lcpr case=start
// [1]\n3\n1\n
// @lcpr case=end

 */

