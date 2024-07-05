/*
 * @lc app=leetcode.cn id=133 lang=cpp
 * @lcpr version=30202
 *
 * [133] 克隆图
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
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        unordered_map<int, Node*> mapper;
        Node *result = new Node(node->val);
        mapper[node->val] = result;

        queue<Node*> que;
        que.push(node);
        while (!que.empty()) {
            Node *curr = que.front();
            que.pop();
            Node *currClone = mapper[curr->val];
            for (auto next : curr->neighbors) {
                if (!mapper.count(next->val)) {
                    Node *nextClone = new Node(next->val);
                    mapper[next->val] = nextClone;
                    que.push(next);
                }
                currClone->neighbors.push_back(mapper[next->val]);
            }
        }
        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,4],[1,3],[2,4],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

