/*
 * @lc app=leetcode.cn id=3072 lang=cpp
 * @lcpr version=30202
 *
 * [3072] 将元素分配到两个数组中 II
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
#include <map>
#include <set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    class BTT {
    public:
        BTT(int n) : n(n), tree(n + 1) {}
        int n;
        vector<int> tree;

        int lowbit(int i) {
            return i & -i;
        }

        int get(int i) {
            int sum = 0;
            while (i > 0) {
                sum += tree[i];
                i = i - lowbit(i);
            }
            return sum;
        }

        void add(int i) {
            while (i <= n) {
                tree[i] += 1;
                i = i + lowbit(i);
            }
        }
    };

    vector<int> resultArray(vector<int>& nums) {
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());
        int n = temp.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[temp[i]] = i + 1;
        }

        BTT btt1(n), btt2(n);

        vector<int> ans1, ans2;
        ans1.push_back(nums[0]);
        btt1.add(mp[nums[0]]);
        ans2.push_back(nums[1]);
        btt2.add(mp[nums[1]]);

        for (int i = 2; i < nums.size(); ++i) {
            int gc1 = ans1.size() - btt1.get(mp[nums[i]]);
            int gc2 = ans2.size() - btt2.get(mp[nums[i]]);

            if (gc1 > gc2 || (gc1 == gc2 && ans1.size() <= ans2.size())) {
                ans1.push_back(nums[i]);
                btt1.add(mp[nums[i]]);
            } else {
                ans2.push_back(nums[i]);
                btt2.add(mp[nums[i]]);
            }

        }

        ans1.insert(ans1.end(), ans2.begin(), ans2.end());
        return ans1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,14,3,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,3,3]\n
// @lcpr case=end

 */

