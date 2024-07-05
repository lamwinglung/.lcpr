/*
 * @lc app=leetcode.cn id=189 lang=cpp
 * @lcpr version=30202
 *
 * [189] 轮转数组
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
    int gcd(int m, int n) {
        if (m < n) {
            swap(m, n);
        }
        int k;
        while ((k = m % n) != 0) {
            m = n;
            n = k;
        }
        return n;
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0) {
            return;
        }

        int count = gcd(k, n);

        for (int i = 0; i < count; ++i) {
            int start = i;
            int prev = start;
            int cacheNum = nums[i];
            do {
                int next = (k + prev) % n;
                swap(cacheNum, nums[next]);
                prev = next;
            } while (prev != start);
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [-1,-100,3,99]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6,7]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6]\n12\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

