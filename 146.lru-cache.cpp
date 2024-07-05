/*
 * @lc app=leetcode.cn id=146 lang=cpp
 * @lcpr version=30202
 *
 * [146] LRU 缓存
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
class LRUCache {
public:
    struct Node {
        Node() {}
        Node(int key, int val) : key(key), val(val) {}

        Node *prev = nullptr;
        Node *next = nullptr;
        int key;
        int val;
    };

    LRUCache(int capacity) : capacity(capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(Node *node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void moveToHead(Node *node) {
        removeNode(node);
        addToHead(node);
    }

    Node *removeTail() {
        Node *node = tail->prev;
        removeNode(node);
        return node;
    }

    int get(int key) {
        if (!table.count(key)) {
            return -1;
        }
        Node *node = table[key];
        moveToHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (table.count(key)) {
            Node *node = table[key];
            node->val = value;
            moveToHead(node);
            return;
        }

        Node *node = new Node(key, value);
        table[key] = node;
        addToHead(node);

        if (table.size() > capacity) {
            Node *removeNode = removeTail();
            table.erase(removeNode->key);
            delete removeNode;
        }
    }

    Node *head;
    Node *tail;
    unordered_map<int, Node *> table;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end



