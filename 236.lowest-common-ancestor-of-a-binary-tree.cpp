/*
 * @lc app=leetcode.cn id=236 lang=cpp
 * @lcpr version=30202
 *
 * [236] 二叉树的最近公共祖先
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto count = [&] (TreeNode *node) {
            queue<TreeNode *> que;
            que.push(node);
            int sum = 0;
            while (!que.empty()) {
                TreeNode *curr = que.front();
                que.pop();
                if (curr == p || curr == q) {
                    ++sum;
                }
                if (sum == 2) {
                    break;
                }
                if (curr) {
                    que.push(curr->left);
                    que.push(curr->right);
                }
            }
            return sum;
        };

        function<TreeNode *(TreeNode *)> find = [&] (TreeNode *node) -> TreeNode * {
            if (node == nullptr) {
                return nullptr;
            }
            if (node == p || node == q) {
                return node;
            }
            int cnt = count(node->left);
            if (cnt == 0) {
                return find(node->right);
            } else if (cnt == 2) {
                return find(node->left);
            }
            return node;
        };

        return find(root);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n1\n
// @lcpr case=end

// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n2\n
// @lcpr case=end

 */

