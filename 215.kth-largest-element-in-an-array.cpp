/*
 * @lc app=leetcode.cn id=215 lang=cpp
 * @lcpr version=30202
 *
 * [215] 数组中的第K个最大元素
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

    int adjust(vector<int> &nums, int l, int r) {
        int x = nums[l];
        int i = l, j = r;
        while (i < j) {
            while (i < j && nums[j] >= x) {
                --j;
            }
            if (i < j) {
                nums[i] = nums[j];
                ++i;
            }

            while (i < j && nums[i] < x) {
                ++i;
            }
            if (i < j) {
                nums[j] = nums[i];
                --j;
            }
        }
        nums[i] = x;
        return i;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int x = adjust(nums, l, r);
            if (x < nums.size() - k) {
                l = x + 1;
            } else if (x > nums.size() - k) {
                r = x - 1;
            } else {
                break;
            }
        }
        return nums[nums.size() - k];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,3,1,5,6,6,7,7,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [4,3,1,5,6,7,3,0,9]\n4\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

