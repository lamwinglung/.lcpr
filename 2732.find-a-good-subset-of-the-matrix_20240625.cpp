/*
 * @lc app=leetcode.cn id=2732 lang=cpp
 * @lcpr version=30204
 *
 * [2732] 找到矩阵中的好子集
 *
 * https://leetcode.cn/problems/find-a-good-subset-of-the-matrix/description/
 *
 * algorithms
 * Hard (55.09%)
 * Likes:    29
 * Dislikes: 0
 * Total Accepted:    5.4K
 * Total Submissions: 7.9K
 * Testcase Example:  '[[0,1,1,0],[0,0,0,1],[1,1,1,1]]'
 *
 * 给你一个下标从 0 开始大小为 m x n 的二进制矩阵 grid 。
 * 
 * 从原矩阵中选出若干行构成一个行的 非空 子集，如果子集中任何一列的和至多为子集大小的一半，那么我们称这个子集是 好子集。
 * 
 * 更正式的，如果选出来的行子集大小（即行的数量）为 k，那么每一列的和至多为 floor(k / 2) 。
 * 
 * 请你返回一个整数数组，它包含好子集的行下标，请你将子集中的元素 升序 返回。
 * 
 * 如果有多个好子集，你可以返回任意一个。如果没有好子集，请你返回一个空数组。
 * 
 * 一个矩阵 grid 的行 子集 ，是删除 grid 中某些（也可能不删除）行后，剩余行构成的元素集合。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：grid = [[0,1,1,0],[0,0,0,1],[1,1,1,1]]
 * 输出：[0,1]
 * 解释：我们可以选择第 0 和第 1 行构成一个好子集。
 * 选出来的子集大小为 2 。
 * - 第 0 列的和为 0 + 0 = 0 ，小于等于子集大小的一半。
 * - 第 1 列的和为 1 + 0 = 1 ，小于等于子集大小的一半。
 * - 第 2 列的和为 1 + 0 = 1 ，小于等于子集大小的一半。
 * - 第 3 列的和为 0 + 1 = 1 ，小于等于子集大小的一半。
 * 
 * 
 * 示例 2：
 * 
 * 输入：grid = [[0]]
 * 输出：[0]
 * 解释：我们可以选择第 0 行构成一个好子集。
 * 选出来的子集大小为 1 。
 * - 第 0 列的和为 0 ，小于等于子集大小的一半。
 * 
 * 
 * 示例 3：
 * 
 * 输入：grid = [[1,1,1],[1,1,1]]
 * 输出：[]
 * 解释：没有办法得到一个好子集。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m <= 10^4
 * 1 <= n <= 5
 * grid[i][j] 要么是 0 ，要么是 1 。
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
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1,1,0],[0,0,0,1],[1,1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1],[1,1,1]]\n
// @lcpr case=end

 */

