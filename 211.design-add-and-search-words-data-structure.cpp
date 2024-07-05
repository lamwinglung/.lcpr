/*
 * @lc app=leetcode.cn id=211 lang=cpp
 * @lcpr version=30202
 *
 * [211] 添加与搜索单词 - 数据结构设计
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
class WordDictionary {
public:
    struct Node {
        vector<Node *> children;
        bool isEnd;
        Node() : children(26, nullptr), isEnd(false) {}
    };

    WordDictionary() : root(new Node()) {}

    Node *root;

    void addWord(string word) {
        Node *node = root;
        for (char c : word) {
            int ch = c - 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Node();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }
    
    bool dfs(Node *node, const string &word, int deep) {
        if (node == nullptr) {
            return false;
        }
        if (word.size() == deep) {
            return node->isEnd;
        }
        if (word[deep] == '.') {
            for (int i = 0; i < 26; ++i) {
                if (dfs(node->children[i], word, deep + 1)) {
                    return true;
                }
            }
        } else {
            int ch = word[deep] - 'a';
            if (dfs(node->children[ch], word, deep + 1)) {
                return true;
            }
        }
        return false;
    }

    bool search(string word) {
        return dfs(root, word, 0);

        queue<Node *> que;
        que.push(root);

        int deep = 0;
        while (!que.empty()) {
            int sz = que.size();
            for (int i = 0; i < sz; ++i) {
                Node *node = que.front();
                que.pop();

                if (word[deep] == '.') {
                    for (int j = 0; j < 26; ++j) {
                        if (node->children[j] != nullptr) {
                            que.push(node->children[j]);
                        }
                    }
                } else {
                    int ch = word[deep] - 'a';
                    if (node->children[ch] != nullptr) {
                        que.push(node->children[ch]);
                    }
                }
            }
            deep += 1;
            if (deep == word.size()) {
                break;
            }
        }

        while (!que.empty()) {
            if (que.front()->isEnd) {
                return true;
            }
            que.pop();
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end



/*
// @lcpr case=start
// ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]\n
// @lcpr case=end

// @lcpr case=start
// ["WordDictionary","addWord","search"]\n[[],["bad"],["bad"]]\n
// @lcpr case=end

 */

