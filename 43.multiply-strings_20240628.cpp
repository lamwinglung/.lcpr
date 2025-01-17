/*
 * @lc app=leetcode.cn id=43 lang=cpp
 * @lcpr version=30204
 *
 * [43] 字符串相乘
 *
 * https://leetcode.cn/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (44.32%)
 * Likes:    1346
 * Dislikes: 0
 * Total Accepted:    347.3K
 * Total Submissions: 783.1K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * 
 * 注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 * 
 * 示例 2:
 * 
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= num1.length, num2.length <= 200
 * num1 和 num2 只能由数字组成。
 * num1 和 num2 都不包含任何前导零，除了数字0本身。
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
    string multiply(string num1, string num2) {
        if (num1.size() < num2.size()) {
            swap(num1, num2);
        }
        reverse(num1.begin(), num2.end());
        reverse(num2.begin(), num2.end());

        auto calc = [](char a, char b) -> int {
            return (a - '0') * (b - '0');
        };

        int carry = 0;
        string ans;
        for (int i = 0; i < num1.size(); ++i) {
            if (i < num2.size()) {
                int num = calc(num1[i], num2[i]);
                num += carry;
                ans.push_back('0' + num % 10);
                carry = num / 10;
            } else {
                int num = num1[i] - '0';
                num += carry;
                ans.push_back('0' + num % 10);
                carry = num / 10;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "2"\n"3"\n
// @lcpr case=end

// @lcpr case=start
// "123"\n"456"\n
// @lcpr case=end

 */

