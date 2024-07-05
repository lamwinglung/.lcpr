/*
 * @lc app=leetcode.cn id=3099 lang=cpp
 * @lcpr version=30204
 *
 * [3099] 哈沙德数
 *
 * https://leetcode.cn/problems/harshad-number/description/
 *
 * algorithms
 * Easy (83.20%)
 * Likes:    13
 * Dislikes: 0
 * Total Accepted:    13.9K
 * Total Submissions: 16.2K
 * Testcase Example:  '18'
 *
 * 如果一个整数能够被其各个数位上的数字之和整除，则称之为 哈沙德数（Harshad number）。给你一个整数 x 。如果 x 是 哈沙德数 ，则返回
 * x 各个数位上的数字之和，否则，返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： x = 18
 * 
 * 输出： 9
 * 
 * 解释：
 * 
 * x 各个数位上的数字之和为 9 。18 能被 9 整除。因此 18 是哈沙德数，答案是 9 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： x = 23
 * 
 * 输出： -1
 * 
 * 解释：
 * 
 * x 各个数位上的数字之和为 5 。23 不能被 5 整除。因此 23 不是哈沙德数，答案是 -1 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= x <= 100
 * 
 * 
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
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int n = x;
        int sum = 0;
        while (n > 0) {
            sum += (n % 10);
            n /= 10;
        }
        return (sum != 0 && x % sum == 0) ? sum : -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 18\n
// @lcpr case=end

// @lcpr case=start
// 23\n
// @lcpr case=end

 */

