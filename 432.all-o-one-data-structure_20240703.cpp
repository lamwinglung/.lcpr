/*
 * @lc app=leetcode.cn id=432 lang=cpp
 * @lcpr version=30204
 *
 * [432] 全 O(1) 的数据结构
 *
 * https://leetcode.cn/problems/all-oone-data-structure/description/
 *
 * algorithms
 * Hard (46.42%)
 * Likes:    317
 * Dislikes: 0
 * Total Accepted:    30.6K
 * Total Submissions: 66K
 * Testcase Example:
 '["AllOne","inc","inc","getMaxKey","getMinKey","inc","getMaxKey","getMinKey"]\n' +
  '[[],["hello"],["hello"],[],[],["leet"],[],[]]'
 *
 * 请你设计一个用于存储字符串计数的数据结构，并能够返回计数最小和最大的字符串。
 *
 * 实现 AllOne 类：
 *
 *
 * AllOne() 初始化数据结构的对象。
 * inc(String key) 字符串 key 的计数增加 1 。如果数据结构中尚不存在 key ，那么插入计数为 1 的 key 。
 * dec(String key) 字符串 key 的计数减少 1 。如果 key 的计数在减少后为 0 ，那么需要将这个 key
 * 从数据结构中删除。测试用例保证：在减少计数前，key 存在于数据结构中。
 * getMaxKey() 返回任意一个计数最大的字符串。如果没有元素存在，返回一个空字符串 "" 。
 * getMinKey() 返回任意一个计数最小的字符串。如果没有元素存在，返回一个空字符串 "" 。
 *
 *
 * 注意：每个函数都应当满足 O(1) 平均时间复杂度。
 *
 *
 *
 * 示例：
 *
 * 输入
 * ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey",
 * "getMinKey"]
 * [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
 * 输出
 * [null, null, null, "hello", "hello", null, "hello", "leet"]
 *
 * 解释
 * AllOne allOne = new AllOne();
 * allOne.inc("hello");
 * allOne.inc("hello");
 * allOne.getMaxKey(); // 返回 "hello"
 * allOne.getMinKey(); // 返回 "hello"
 * allOne.inc("leet");
 * allOne.getMaxKey(); // 返回 "hello"
 * allOne.getMinKey(); // 返回 "leet"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= key.length <= 10
 * key 由小写英文字母组成
 * 测试用例保证：在每次调用 dec 时，数据结构中总存在 key
 * 最多调用 inc、dec、getMaxKey 和 getMinKey 方法 5 * 10^4 次
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
class AllOne {
public:
    AllOne() {}

    struct KeySet {
        KeySet(int count, unordered_set<string> keys) : count(count), keys(keys) {}
        int count = 1;
        unordered_set<string> keys;
    };

    list<KeySet> cache;
    unordered_map<string, list<KeySet>::iterator> table;

    void inc(string key) {
        if (table.count(key)) {
            auto cur = table[key];
            auto next = std::next(cur);
            if (next == cache.end() || next->count > cur->count + 1) {
                table[key] = cache.emplace(next, cur->count + 1, unordered_set<string>{key});
            } else {
                next->keys.emplace(key);
                table[key] = next;
            }
            cur->keys.erase(key);
            if (cur->keys.empty()) {
                cache.erase(cur);
            }
        } else {
            if (cache.empty() || cache.begin()->count > 1) {
                cache.emplace_front(1, unordered_set<string>{key});
            } else {
                cache.begin()->keys.emplace(key);
            }
            table[key] = cache.begin();
        }
    }

    void dec(string key) {
        if (!table.count(key)) {
            return;
        }
        auto cur = table[key];
        if (cur->count == 1) {
            table.erase(key);
        } else {
            auto prev = std::prev(cur);
            if (cur == cache.begin() || prev->count < cur->count - 1) {
                table[key] = cache.emplace(cur, cur->count - 1, unordered_set<string>{key});
            } else {
                prev->keys.emplace(key);
                table[key] = prev;
            }
        }
        cur->keys.erase(key);
        if (cur->keys.empty()) {
            cache.erase(cur);
        }
    }

    string getMaxKey() { return cache.empty() ? "" : *(cache.rbegin()->keys.begin()); }

    string getMinKey() { return cache.empty() ? "" : *(cache.begin()->keys.begin()); }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end

/*
// @lcpr case=start
// ["AllOne","inc","inc","getMaxKey","getMinKey","inc","getMaxKey","getMinKey"]\n[[],["hello"],["hello"],[],[],["leet"],[],[]]\n
// @lcpr case=end

 */