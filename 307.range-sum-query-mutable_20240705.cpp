/*
 * @lc app=leetcode.cn id=307 lang=cpp
 * @lcpr version=30204
 *
 * [307] 区域和检索 - 数组可修改
 *
 * https://leetcode.cn/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (53.42%)
 * Likes:    727
 * Dislikes: 0
 * Total Accepted:    89.9K
 * Total Submissions: 168.1K
 * Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * 给你一个数组 nums ，请你完成两类查询。
 * 
 * 
 * 其中一类查询要求 更新 数组 nums 下标对应的值
 * 另一类查询要求返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 ，其中 left <= right
 * 
 * 
 * 实现 NumArray 类：
 * 
 * 
 * NumArray(int[] nums) 用整数数组 nums 初始化对象
 * void update(int index, int val) 将 nums[index] 的值 更新 为 val
 * int sumRange(int left, int right) 返回数组 nums 中索引 left 和索引 right 之间（ 包含
 * ）的nums元素的 和 （即，nums[left] + nums[left + 1], ..., nums[right]）
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：
 * ["NumArray", "sumRange", "update", "sumRange"]
 * [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
 * 输出：
 * [null, 9, null, 8]
 * 
 * 解释：
 * NumArray numArray = new NumArray([1, 3, 5]);
 * numArray.sumRange(0, 2); // 返回 1 + 3 + 5 = 9
 * numArray.update(1, 2);   // nums = [1,2,5]
 * numArray.sumRange(0, 2); // 返回 1 + 2 + 5 = 8
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 3 * 10^4
 * -100 <= nums[i] <= 100
 * 0 <= index < nums.length
 * -100 <= val <= 100
 * 0 <= left <= right < nums.length
 * 调用 update 和 sumRange 方法次数不大于 3 * 10^4 
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
class NumArray {
public:
    class BTT {
    public:
        vector<int> tree;
        BTT(int n) : tree(n + 1, 0) {}
        int lowbit(int i) {
            return i & -i;
        }
        void add(int i, int num) {
            while (i < tree.size()) {
                tree[i] += num;
                i = i + lowbit(i);
            }
        }
        int prefixSum(int i) {
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
        btt.add(index + 1, -nums[index]);
        nums[index] = val;
        btt.add(index + 1, nums[index]);
    }
    
    int sumRange(int left, int right) {
        return btt.prefixSum(right + 1) - btt.prefixSum(left);
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

