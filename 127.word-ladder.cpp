/*
 * @lc app=leetcode.cn id=127 lang=cpp
 * @lcpr version=30201
 *
 * [127] 单词接龙
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
class Solution {
public:
    int ladderLength(string beginWord, string endWord, const vector<string>& wordList) {
        vector<unordered_set<int>> table;
        unordered_map<string, int> wordId;
        int incrId = 0;
        auto getWordId = [&](const string &word) -> int {
            auto it = wordId.find(word);
            if (wordId.find(word) == wordId.end()) {
                table.emplace_back();
                wordId[word] = incrId;
                ++incrId;
            }
            return wordId[word];
        };

        auto addEdge = [&](const string &word) -> void {
            string mask = word;
            int id = getWordId(word);
            for (char &c : mask) {
                char tmp = c;
                c = '*';
                int maskId = getWordId(mask);
                table[id].insert(maskId);
                table[maskId].insert(id);
                c = tmp;
            }
        };

        addEdge(beginWord);
        for (const auto &word : wordList) {
            addEdge(word);
        }

        if (wordId.find(endWord) == wordId.end()) {
            return 0;
        }

        addEdge(endWord);

        queue<int> que;
        unordered_set<int> visted;
        
        int beginId = getWordId(beginWord);
        int endId = getWordId(endWord);

        que.push(beginId);
        visted.insert(beginId);

        int step = 0;
        while (!que.empty()) {
            int n = que.size();
            for (int i = 0; i < n; ++i) {
                int front = que.front();
                que.pop();
                if (front == endId) {
                    return step / 2 + 1;
                }
                for (int id : table[front]) {
                    if (!visted.count(id)) {
                        que.push(id);
                        visted.insert(id);
                    }
                }
            }
            ++step;
        }
        return 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]\n
// @lcpr case=end

// @lcpr case=start
// "hit"\n"cog"\n["hot","dot","dog","lot","log"]\n
// @lcpr case=end

// @lcpr case=start
// "hit"\n"hot"\n["hit","hot"]\n
// @lcpr case=end


 */

