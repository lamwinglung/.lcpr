/*
 * @lc app=leetcode.cn id=210 lang=cpp
 * @lcpr version=30202
 *
 * [210] 课程表 II
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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> edges(numCourses);
        vector<int> indeg(numCourses, 0);
        for (auto &edge : prerequisites) {
            edges[edge[1]].push_back(edge[0]);
            indeg[edge[0]] += 1;
        }

        unordered_set<int> visted;
        vector<int> que;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                que.push_back(i);
                visted.insert(i);
            }
        }
        for (int i = 0; i < que.size(); ++i) {
            int cur = que[i];
            for (auto &next : edges[cur]) {
                if (indeg[next] > 0) {
                    indeg[next] -= 1;
                }
                if (indeg[next] == 0 && !visted.count(next)) {
                    que.push_back(next);
                    visted.insert(next);
                }
            }
        }
        return que.size() == numCourses ? que : vector<int>{};
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,0],[2,0],[3,1],[3,2]]\n
// @lcpr case=end

// @lcpr case=start
// 1\n[]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0],[0,1]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,1],[0,2],[1,2]]\n
// @lcpr case=end

 */

