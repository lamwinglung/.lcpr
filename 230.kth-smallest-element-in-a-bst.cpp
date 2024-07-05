/*
 * @lc app=leetcode.cn id=230 lang=cpp
 * @lcpr version=30202
 *
 * [230] 二叉搜索树中第K小的元素
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

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        unordered_map<TreeNode*, int> count;
        count[nullptr] = 0;
        function<int(TreeNode *)> countNodeNum = [&](TreeNode *node) {
            if (node == nullptr) {
                return 0;
            }
            int sum = 1 + countNodeNum(node->left) + countNodeNum(node->right);
            count[node] = sum;
            return sum;
        };
        countNodeNum(root);
        
        function<int(TreeNode *, int)> kth = [&](TreeNode *root, int k) -> int {
            if (root == nullptr) {
                return -1;
            }
            if (count[root->left] > k) {
                return kth(root->left, k);
            } else if (count[root->left] < k) {
                return kth(root->right, k - count[root->left] - 1);
            }
            return root->val;
        };

        return kth(root, k - 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1,4,null,2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,null,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2]\n2\n
// @lcpr case=end

 */

