/*
 * @lc app=leetcode.cn id=71 lang=cpp
 * @lcpr version=30201
 *
 * [71] 简化路径
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
    vector<string> split(const string &s, char c) {
        vector<string> result;
        int start = 0;
        while (start < s.size()) {
            int end = s.find(c, start);
            if (end == string::npos) {
                end = s.size();
            }
            string word = s.substr(start, end - start);
            result.push_back(word);
            start = end + 1;
        }
        return result;
    }

    string simplifyPath(string path) {

        vector<string> dirs = split(path, '/');

        vector<string> stk;
        for (auto dir : dirs) {
            cout << "dir: " << dir << endl;
            if (dir.empty() || dir == ".") {
                continue;
            } else if (dir == "..") {
                if ( !stk.empty()) {
                    stk.pop_back();
                }
            } else {
                stk.push_back(dir);
            }
        }

        if (stk.empty()) {
            return "/";
        }

        string result;
        for (auto &dir : stk) {
            result = result + "/" + dir;
        }

        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "/home/"\n
// @lcpr case=end

// @lcpr case=start
// "/../"\n
// @lcpr case=end

// @lcpr case=start
// "/home//foo/"\n
// @lcpr case=end

// @lcpr case=start
// "/a/./b/../../c/"\n
// @lcpr case=end

// @lcpr case=start
// "/home/user/Documents/../Pictures"\n
// @lcpr case=end

 */

