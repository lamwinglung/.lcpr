/*
 * @lc app=leetcode.cn id=373 lang=cpp
 * @lcpr version=30202
 *
 * [373] 查找和最小的 K 对数字
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
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&](pair<int, int> &left, pair<int, int> &right) {
            return (nums1[left.first] + nums2[left.second]) > (nums1[right.first] + nums2[right.second]);
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        int m = nums1.size(), n = nums2.size();
        for (int i = 0; i < min(k, m); ++i) {
            pq.emplace(i, 0);
        }

        vector<vector<int>> ans;
        while (k-- > 0 && !pq.empty()) {
            auto [x, y] = pq.top();
            pq.pop();
            ans.emplace_back(initializer_list<int>{nums1[x], nums2[y]});
            if (y + 1 < n) {
                pq.emplace(x, y + 1);
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,7,11]\n[2,4,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2]\n[1,2,3]\n2\n
// @lcpr case=end

 */

