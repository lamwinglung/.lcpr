/*
 * @lc app=leetcode.cn id=380 lang=cpp
 * @lcpr version=30202
 *
 * [380] O(1) 时间插入、删除和获取随机元素
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
class RandomizedSet {
public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    unordered_map<int, int> indices;
    vector<int> nums;

    bool insert(int val) {
        if (indices.count(val)) {
            return false;
        }
        nums.push_back(val);
        indices[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!indices.count(val)) {
            return false;
        }
        int index = indices[val];
        indices[nums.back()] = index;
        nums[index] = nums.back();
        nums.pop_back();
        indices.erase(val);
        return true;
    }
    
    int getRandom() {
        int index = rand() % nums.size();
        return nums[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

/*
// @lcpr case=start
// ["RandomizedSet","remove","remove","insert","getRandom","remove","insert"]\n[[],[0],[0],[0],[],[0],[0]]
// @lcpr case=end

// @lcpr case=start
// [1,0,48,null,null,12,49]\n
// @lcpr case=end

 */


