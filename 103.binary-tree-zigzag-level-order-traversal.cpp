/*
 * @lc app=leetcode.cn id=103 lang=cpp
 * @lcpr version=30202
 *
 * [103] 二叉树的锯齿形层序遍历
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            int sz = que.size();
            vector<int> vals;
            for (int i = 0; i < sz; ++i) {
                TreeNode *node = que.front();
                que.pop();
                if (node) {
                    vals.push_back(node->val);
                    if (node->left) {
                        que.push(node->left);
                    }
                    if (node->right) {
                        que.push(node->right);
                    }
                }
            }
            ans.emplace_back(move(vals));
        }
        for (int i = 1; i < ans.size(); i += 2) {
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

