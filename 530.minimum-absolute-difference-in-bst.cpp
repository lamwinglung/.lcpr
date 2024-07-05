/*
 * @lc app=leetcode.cn id=530 lang=cpp
 * @lcpr version=30202
 *
 * [530] 二叉搜索树的最小绝对差
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
    int getMinimumDifference(TreeNode* root) {
        int pre = -1;
        int ans = INT_MAX;
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (node == nullptr) {
                return;
            }
            dfs(node->left);
            if (pre == -1) {
                pre = node->val;
            } else {
                ans = min(ans, node->val - pre);
                pre = node->val;
            }
            dfs(node->right);
        };
        dfs(root);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,6,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,48,null,null,12,49]\n
// @lcpr case=end

 */

