/*
 * @lc app=leetcode.cn id=289 lang=cpp
 * @lcpr version=30203
 *
 * [289] 生命游戏
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
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int count = board[i][j] == 1 ? -1 : 0;
                for (int x = max(0, i - 1); x <= min(m - 1, i + 1); ++x) {
                    for (int y = max(0, j - 1); y <= min(n - 1, j + 1); ++y) {
                        if (board[x][y] == 1 || board[x][y] == -1) {
                            ++count;
                        }
                    }
                }
                if (board[i][j] == 1) {
                    if (count < 2 || count > 3) {
                        board[i][j] = -1;
                    }
                } else if (board[i][j] == 0) {
                    if (count == 3) {
                        board[i][j] = 2;
                    }
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == -1) {
                    board[i][j] = 0;
                } else if (board[i][j] == 2) {
                    board[i][j] = 1;
                }
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,0,0,0,1],[0,0,1,1,1,1],[1,1,1,0,1,1],[0,0,1,1,1,1],[0,0,0,1,1,1],[0,1,0,0,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1]]\n
// @lcpr case=end

 */

