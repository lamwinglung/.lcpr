/*
 * @lc app=leetcode.cn id=52 lang=cpp
 * @lcpr version=30201
 *
 * [52] N 皇后 II
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
    int result = 0;
    unordered_set<int> column;
    unordered_set<int> slashSum;
    unordered_set<int> slashSub;

    void backtrace(int pos, int n) {
        if (pos == n) {
            ++result;
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (column.count(i) || slashSum.count(pos + i) || slashSub.count(pos - i)) {
                continue;
            }
            column.insert(i);
            slashSum.insert(pos + i);
            slashSub.insert(pos - i);
            backtrace(pos + 1, n);
            column.erase(i);
            slashSum.erase(pos + i);
            slashSub.erase(pos - i);
        }
    }

    int totalNQueens(int n) {
        result = 0;
        backtrace(0, n);
        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 9\n
// @lcpr case=end

 */

