/*
 * @lc app=leetcode.cn id=86 lang=cpp
 * @lcpr version=30201
 *
 * [86] 分隔链表
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


// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lead(-1, head);
        ListNode *last = &lead;
        while (last->next && last->next->val < x) {
            last = last->next;
        }

        ListNode *p = last;
        while (p->next) {
            if (p->next->val < x) {
                ListNode *tmp = p->next;
                p->next = tmp->next;
                tmp->next = last->next;
                last->next = tmp;
                last = last->next;
            } else {
                p = p->next;
            }
        }
        return lead.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// []\n0\n
// @lcpr case=end

// @lcpr case=start
// [1,4,3,2,5,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [4,3,2,5,2,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

// @lcpr case=start
// [4,3,2,5,2,1]\n6\n
// @lcpr case=end

// @lcpr case=start
// [4,3,2,5,2,1]\n0\n
// @lcpr case=end

 */

