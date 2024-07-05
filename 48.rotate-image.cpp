/*
 * @lc app=leetcode.cn id=48 lang=cpp
 * @lcpr version=30201
 *
 * [48] 旋转图像
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
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.size();

        auto convertLeftUp = [m, n](int x, int y) -> pair<int, int> {
            return {y, n - 1 - x};
        };
        auto convertRightUp = [m, n](int x, int y) -> pair<int, int> {
            y = n - 1 - y;
            return {m - 1 - y, n - 1 - x};
        };
        auto convertRightDown = [m, n](int x, int y) -> pair<int, int> {
            x = m - 1 - x;
            y = n - 1 - y;
            return {m - 1 - y, x};
        };
        auto convertLeftDown = [m, n](int x, int y) -> pair<int, int> {
            x = m - 1 - x;
            return {y, x};
        };

        vector<function<pair<int, int>(int, int)>> convertFuncList{
            convertLeftUp, convertRightUp, convertRightDown, convertLeftDown
        };

        for (int i = 0; i < m / 2; ++i) {
            for (int j = 0; j < n / 2 + (n & 1); ++j) {
                int ci = i, cj = j;
                int tmp = matrix[ci][cj];
                for (auto func : convertFuncList) {
                    int value = tmp;
                    auto p = func(ci, cj);
                    ci = p.first, cj = p.second;
                    tmp = matrix[ci][cj];
                    matrix[ci][cj] = value;
                }
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]\n
// @lcpr case=end

// @lcpr case=start
// [[1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,4]]\n
// @lcpr case=end

 */

