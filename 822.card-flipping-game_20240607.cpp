/*
 * @lc app=leetcode.cn id=822 lang=cpp
 * @lcpr version=30203
 *
 * [822] 翻转卡片游戏
 *
 * https://leetcode.cn/problems/card-flipping-game/description/
 *
 * algorithms
 * Medium (59.54%)
 * Likes:    119
 * Dislikes: 0
 * Total Accepted:    25.8K
 * Total Submissions: 43.4K
 * Testcase Example:  '[1,2,4,4,7]\n[1,3,4,1,3]'
 *
 * 在桌子上有 n 张卡片，每张卡片的正面和背面都写着一个正数（正面与背面上的数有可能不一样）。
 * 
 * 我们可以先翻转任意张卡片，然后选择其中一张卡片。
 * 
 * 如果选中的那张卡片背面的数字 x 与任意一张卡片的正面的数字都不同，那么这个数字是我们想要的数字。
 * 
 * 哪个数是这些想要的数字中最小的数（找到这些数中的最小值）呢？如果没有一个数字符合要求的，输出 0 。
 * 
 * 其中, fronts[i] 和 backs[i] 分别代表第 i 张卡片的正面和背面的数字。
 * 
 * 如果我们通过翻转卡片来交换正面与背面上的数，那么当初在正面的数就变成背面的数，背面的数就变成正面的数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：fronts = [1,2,4,4,7], backs = [1,3,4,1,3]
 * 输出：2
 * 解释：假设我们翻转第二张卡片，那么在正面的数变成了 [1,3,4,4,7] ， 背面的数变成了 [1,2,4,1,3]。
 * 接着我们选择第二张卡片，因为现在该卡片的背面的数是 2，2 与任意卡片上正面的数都不同，所以 2 就是我们想要的数字。
 * 
 * 示例 2：
 * 
 * 输入：fronts = [1], backs = [1]
 * 输出：0
 * 解释：
 * 无论如何翻转都无法得到想要的数字，所以返回 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == fronts.length == backs.length
 * 1 <= n <= 1000
 * 1 <= fronts[i], backs[i] <= 2000
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
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int n = fronts.size();
        unordered_set<int> same;
        for (int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) {
                same.insert(fronts[i]);
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (!same.count(fronts[i])) {
                ans = min(ans, fronts[i]);
            }
            if (!same.count(backs[i])) {
                ans = min(ans, backs[i]);
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,4,4,7]\n[1,3,4,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n[1]\n
// @lcpr case=end

 */

