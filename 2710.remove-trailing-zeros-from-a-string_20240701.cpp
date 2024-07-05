/*
 * @lc app=leetcode.cn id=2710 lang=cpp
 * @lcpr version=30204
 *
 * [2710] 移除字符串中的尾随零
 *
 * https://leetcode.cn/problems/remove-trailing-zeros-from-a-string/description/
 *
 * algorithms
 * Easy (81.69%)
 * Likes:    27
 * Dislikes: 0
 * Total Accepted:    25.3K
 * Total Submissions: 29.5K
 * Testcase Example:  '"51230100"'
 *
 * 给你一个用字符串表示的正整数 num ，请你以字符串形式返回不含尾随零的整数 num 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：num = "51230100"
 * 输出："512301"
 * 解释：整数 "51230100" 有 2 个尾随零，移除并返回整数 "512301" 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：num = "123"
 * 输出："123"
 * 解释：整数 "123" 不含尾随零，返回整数 "123" 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= num.length <= 1000
 * num 仅由数字 0 到 9 组成
 * num 不含前导零
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
    string removeTrailingZeros(string num) {
        while (num.size() > 1 && num.back() == '0') {
            num.pop_back();
        }
        return num;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "51230100"\n
// @lcpr case=end

// @lcpr case=start
// "123"\n
// @lcpr case=end

// @lcpr case=start
// "0000"\n
// @lcpr case=end

// @lcpr case=start
// "0"\n
// @lcpr case=end

 */

