/*
 * @lc app=leetcode.cn id=2225 lang=cpp
 * @lcpr version=30202
 *
 * [2225] 找出输掉零场或一场比赛的玩家
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
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> record;
        for (auto &p : matches) {
            int win = p[0], lose = p[1];
            if (!record.count(win)) {
                record[win] = 0;
            }
            record[lose] -= 1;
        }
        vector<vector<int>> result(2);
        for (auto &[member, count] : record) {
            if (count == 0) {
                result[0].push_back(member);
            } else if (count == -1) {
                result[1].push_back(member);
            }
        }
        for (auto &sub : result) {
            sort(sub.begin(), sub.end());
        }
        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,3],[1,3],[5,4],[6,4]]\n
// @lcpr case=end

 */

