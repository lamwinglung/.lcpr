/*
 * @lc app=leetcode.cn id=207 lang=cpp
 * @lcpr version=30202
 *
 * [207] 课程表
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> edges(numCourses);
        vector<int> indeg(numCourses, 0);
        for (auto &pre : prerequisites) {
            edges[pre[1]].insert(pre[0]);
            indeg[pre[0]] += 1;
        }

        unordered_set<int> visted;
        queue<int> que;

        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                que.push(i);
                visted.insert(i);
            }
        }

        while (!que.empty()) {
            int front = que.front();
            que.pop();
            for (auto &next : edges[front]) {
                if (indeg[next] > 0) {
                    indeg[next] -= 1;
                }
                if (!visted.count(next) && indeg[next] == 0) {
                    que.push(next);
                    visted.insert(next);
                }
            }
        }

        return visted.size() == numCourses;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0],[0,1]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,0],[2,1],[3,1],[3,2]]\n
// @lcpr case=end

 */

