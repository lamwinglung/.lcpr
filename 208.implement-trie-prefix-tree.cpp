/*
 * @lc app=leetcode.cn id=208 lang=cpp
 * @lcpr version=30202
 *
 * [208] 实现 Trie (前缀树)
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
class Trie {
public:
    Trie() {
        root = new Node();
    }
    
    struct Node {
        vector<Node *> children;
        bool isEnd;

        Node() {
            children = vector<Node *>(26, nullptr);
            isEnd = false;
        }
    };

    Node *root;

    void insert(string word) {
        Node *node = root;
        for (char c : word) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                node->children[i] = new Node();
            }
            node = node->children[i];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Node *node = root;
        for (char c : word) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                return false;
            }
            node = node->children[i];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for (char c : prefix) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                return false;
            }
            node = node->children[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end


/*
// @lcpr case=start
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]\n[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]\n
// @lcpr case=end

 */

