/*
 * @lc app=leetcode.cn id=307 lang=cpp
 * @lcpr version=30202
 *
 * [307] 区域和检索 - 数组可修改
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
class NumArray {
public:
    class BTT {
    public:
        vector<int> tree;
        BTT(int n) : tree(n + 1, 0) {}
        int lowbit(int i) {
            return i & -i;
        }
        void add(int i, int val) {
            while (i < tree.size()) {
                tree[i] += val;
                i = i + lowbit(i);
            }
        }
        int getPrefixSum(int i) {
            int sum = 0;
            while (i > 0) {
                sum += tree[i];
                i = i - lowbit(i);
            }
            return sum;
        }
    };

    vector<int> nums;
    BTT btt;

    NumArray(vector<int>& nums) : nums(nums), btt(nums.size()) {
        for (int i = 0; i < nums.size(); ++i) {
            btt.add(i + 1, nums[i]);
        }
    }
    
    void update(int index, int val) {
        btt.add(index + 1, val -nums[index]);
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return btt.getPrefixSum(right + 1) - btt.getPrefixSum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end



/*
// @lcpr case=start
// ["NumArray", "sumRange", "update", "sumRange"]\n[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]\n
// @lcpr case=end

 */

