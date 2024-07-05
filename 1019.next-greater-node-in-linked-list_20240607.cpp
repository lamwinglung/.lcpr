/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 * @lcpr version=30203
 *
 * [1019] 链表中的下一个更大节点
 *
 * https://leetcode.cn/problems/next-greater-node-in-linked-list/description/
 *
 * algorithms
 * Medium (64.75%)
 * Likes:    331
 * Dislikes: 0
 * Total Accepted:    60.5K
 * Total Submissions: 93.3K
 * Testcase Example:  '[2,1,5]'
 *
 * 给定一个长度为 n 的链表 head
 * 
 * 对于列表中的每个节点，查找下一个 更大节点 的值。也就是说，对于每个节点，找到它旁边的第一个节点的值，这个节点的值 严格大于 它的值。
 * 
 * 返回一个整数数组 answer ，其中 answer[i] 是第 i 个节点( 从1开始 )的下一个更大的节点的值。如果第 i
 * 个节点没有下一个更大的节点，设置 answer[i] = 0 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：head = [2,1,5]
 * 输出：[5,5,0]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：head = [2,7,4,3,5]
 * 输出：[7,0,5,5,0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数为 n
 * 1 <= n <= 10^4
 * 1 <= Node.val <= 10^9
 * 
 * 
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<pair<int,int>> t;
        ListNode *node = head;
        int i = 0;
        while (node != nullptr) {
            ans.push_back(0);
            while (!t.empty() && node->val > t.top().first) {
                ans[t.top().second] = node->val;
                t.pop();
            }
            t.emplace(node->val, i);
            ++i;
            node = node->next;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,7,4,3,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,7,3,4,6,3,5]\n
// @lcpr case=end

 */

