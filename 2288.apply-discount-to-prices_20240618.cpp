/*
 * @lc app=leetcode.cn id=2288 lang=cpp
 * @lcpr version=30203
 *
 * [2288] 价格减免
 *
 * https://leetcode.cn/problems/apply-discount-to-prices/description/
 *
 * algorithms
 * Medium (32.05%)
 * Likes:    22
 * Dislikes: 0
 * Total Accepted:    15K
 * Total Submissions: 39.2K
 * Testcase Example:  '"there are $1 $2 and 5$ candies in the shop"\n50'
 *
 * 句子 是由若干个单词组成的字符串，单词之间用单个空格分隔，其中每个单词可以包含数字、小写字母、和美元符号 '$'
 * 。如果单词的形式为美元符号后跟着一个非负实数，那么这个单词就表示一个 价格 。
 * 
 * 
 * 例如 "$100"、"$23" 和 "$6" 表示价格，而 "100"、"$" 和 "$1e5 不是。
 * 
 * 
 * 给你一个字符串 sentence 表示一个句子和一个整数 discount 。对于每个表示价格的单词，都在价格的基础上减免 discount% ，并
 * 更新 该单词到句子中。所有更新后的价格应该表示为一个 恰好保留小数点后两位 的数字。
 * 
 * 返回表示修改后句子的字符串。
 * 
 * 注意：所有价格 最多 为  10 位数字。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：sentence = "there are $1 $2 and 5$ candies in the shop", discount = 50
 * 输出："there are $0.50 $1.00 and 5$ candies in the shop"
 * 解释：
 * 表示价格的单词是 "$1" 和 "$2" 。 
 * - "$1" 减免 50% 为 "$0.50" ，所以 "$1" 替换为 "$0.50" 。
 * - "$2" 减免 50% 为 "$1" ，所以 "$1" 替换为 "$1.00" 。
 * 
 * 示例 2：
 * 
 * 输入：sentence = "1 2 $3 4 $5 $6 7 8$ $9 $10$", discount = 100
 * 输出："1 2 $0.00 4 $0.00 $0.00 7 8$ $0.00 $10$"
 * 解释：
 * 任何价格减免 100% 都会得到 0 。
 * 表示价格的单词分别是 "$3"、"$5"、"$6" 和 "$9"。
 * 每个单词都替换为 "$0.00"。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= sentence.length <= 10^5
 * sentence 由小写英文字母、数字、' ' 和 '$' 组成
 * sentence 不含前导和尾随空格
 * sentence 的所有单词都用单个空格分隔
 * 所有价格都是 正 整数且不含前导零
 * 所有价格 最多 为  10 位数字
 * 0 <= discount <= 100
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
    string discountPrices(string sentence, int discount) {
        vector<string> words;
        size_t pos = 0;
        while (pos < sentence.size()) {
            size_t next = sentence.find(' ', pos);
            if (next != string::npos) {
                words.emplace_back(sentence, pos, next - pos);
            } else {
                words.emplace_back(sentence, pos);
                break;
            }
            pos = next + 1;
        }
        string ans;
        for (auto &word : words) {
            if (word.size() > 1 && word[0] == '$' && all_of(word.begin() + 1, word.end(), ::isdigit)) {
                double price = stoll(word.substr(1, word.size() - 1)) * (1.0 - discount / 100.0);
                word = "$" + to_string(price);
            }
            ans.append(word);
            ans.push_back(' ');
        }
        if (!ans.empty()) {
            ans.pop_back();
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "there are $1 $2 and 5$ candies in the shop"\n50\n
// @lcpr case=end

// @lcpr case=start
// "1 2 $3 4 $5 $6 7 8$ $9 $10$"\n100\n
// @lcpr case=end

 */

