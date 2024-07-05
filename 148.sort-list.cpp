/*
 * @lc app=leetcode.cn id=148 lang=cpp
 * @lcpr version=30202
 *
 * [148] 排序链表
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

    ListNode* merge(ListNode* head1, ListNode *head2) {
        ListNode dummy;
        ListNode *p = &dummy;
        ListNode *p1 = head1;
        ListNode *p2 = head2;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val <= p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if (p1 != nullptr) {
            p->next = p1;
        } else {
            p->next = p2;
        }
        return dummy.next;
    }

    ListNode* sort(ListNode* head, ListNode* tail) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        ListNode *mid = slow;
        return merge(sort(head, mid), sort(mid, tail));
    }

    ListNode* sortList(ListNode* head) {
        return sort(head, nullptr);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1,5,3,4,0]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [-1,5,3,4,0,4,2,1,3]\n
// @lcpr case=end

 */

