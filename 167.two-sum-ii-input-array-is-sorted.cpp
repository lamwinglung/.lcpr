/*
 * @lc app=leetcode.cn id=167 lang=cpp
 * @lcpr version=30202
 *
 * [167] 两数之和 II - 输入有序数组
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
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> table;
        for (int i = 0; i < numbers.size(); ++i) {
            if (table.count(target - numbers[i])) {
                return {table[target - numbers[i]], i + 1};
            }
            if (!table.count(numbers[i])) {
                table[numbers[i]] = i + 1;
            }
        }
        return {};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [-1,0]\n-1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,5]\n4\n
// @lcpr case=end

 */

