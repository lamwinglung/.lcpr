/*
 * @lc app=leetcode.cn id=994 lang=cpp
 * @lcpr version=30201
 *
 * [994] 腐烂的橘子
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
#include <set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        set<pair<int, int>> fresh;
        set<pair<int, int>> bad;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    fresh.insert({i, j});
                } else if (grid[i][j] == 2) {
                    bad.insert({i, j});
                }
            }
        }

        if (fresh.empty()) {
            return 0;
        }

        int count = 0;
        while (!fresh.empty() && !bad.empty()) {
            decltype(bad) newBad;
            for (auto [i, j] : bad) {
                for (auto [di, dj] : vector<pair<int, int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
                    auto it = fresh.find({i + di, j + dj});
                    if (it != fresh.end()) {
                        newBad.insert(*it);
                        fresh.erase(it);
                    }
                }
            }

            ++count;
            swap(newBad, bad);
        }

        return bad.empty() ? -1 : count;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,1,1],[1,1,0],[0,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,1],[0,1,1],[1,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[0]]\n
// @lcpr case=end


 */

