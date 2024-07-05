/*
 * @lc app=leetcode.cn id=658 lang=cpp
 * @lcpr version=30203
 *
 * [658] 找到 K 个最接近的元素
 *
 * https://leetcode.cn/problems/find-k-closest-elements/description/
 *
 * algorithms
 * Medium (47.81%)
 * Likes:    556
 * Dislikes: 0
 * Total Accepted:    101.7K
 * Total Submissions: 212.8K
 * Testcase Example:  '[1,2,3,4,5]\n4\n3'
 *
 * 给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。
 * 
 * 整数 a 比整数 b 更接近 x 需要满足：
 * 
 * 
 * |a - x| < |b - x| 或者
 * |a - x| == |b - x| 且 a < b
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [1,2,3,4,5], k = 4, x = 3
 * 输出：[1,2,3,4]
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = [1,2,3,4,5], k = 4, x = -1
 * 输出：[1,2,3,4]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= k <= arr.length
 * 1 <= arr.length <= 10^4
 * arr 按 升序 排列
 * -10^4 <= arr[i], x <= 10^4
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
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (arr[mid] >= x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        vector<int> ans;
        while (k-- > 0) {
            if (l < n && r >= 0) {
                if (abs(arr[r] - x) <= abs(arr[l] - x)) {
                    --r;
                } else {
                    ++l;
                }
            } else if (l < n) {
                ++l;
            } else if (r >= 0) {
                --r;
            } else 
        }
        return vector<int>(arr.begin() + r + 1, arr.begin() + l);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n4\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n4\n-1\n
// @lcpr case=end

 */

