/*
 * @lc app=leetcode.cn id=106 lang=cpp
 * @lcpr version=30202
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        function<TreeNode*(int,int,int,int)> 
        build = [&](int inLeft, int inRight, int postLeft, int postRight) -> TreeNode* {
            if (inLeft > inRight || postLeft > postRight) {
                return nullptr;
            }
            int val = postorder[postRight];
            int inMid = inLeft;
            for (; inMid <= inRight; ++inMid) {
                if (inorder[inMid] == val) {
                    break;
                }
            }
            int leftSize = inMid - inLeft;
            int rightSize = rightSize - inMid;
            TreeNode *node = new TreeNode(val);
            node->left = build(inLeft, inMid - 1, postLeft, postLeft + leftSize - 1);
            node->right = build(inMid + 1, inRight, postLeft + leftSize, postRight - 1);
            return node;
        };
        return build(0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [9,3,15,20,7]\n[9,15,7,20,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

