/*
 * @lc app=leetcode.cn id=2713 lang=cpp
 * @lcpr version=30203
 *
 * [2713] 矩阵中严格递增的单元格数
 *
 * https://leetcode.cn/problems/maximum-strictly-increasing-cells-in-a-matrix/description/
 *
 * algorithms
 * Hard (36.28%)
 * Likes:    56
 * Dislikes: 0
 * Total Accepted:    4.8K
 * Total Submissions: 11K
 * Testcase Example:  '[[3,1],[3,4]]'
 *
 * 给你一个下标从 1 开始、大小为 m x n 的整数矩阵 mat，你可以选择任一单元格作为 起始单元格 。
 * 
 * 从起始单元格出发，你可以移动到 同一行或同一列 中的任何其他单元格，但前提是目标单元格的值 严格大于 当前单元格的值。
 * 
 * 你可以多次重复这一过程，从一个单元格移动到另一个单元格，直到无法再进行任何移动。
 * 
 * 请你找出从某个单元开始访问矩阵所能访问的 单元格的最大数量 。
 * 
 * 返回一个表示可访问单元格最大数量的整数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：mat = [[3,1],[3,4]]
 * 输出：2
 * 解释：上图展示了从第 1 行、第 2 列的单元格开始，可以访问 2 个单元格。可以证明，无论从哪个单元格开始，最多只能访问 2 个单元格，因此答案是 2
 * 。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：mat = [[1,1],[1,1]]
 * 输出：1
 * 解释：由于目标单元格必须严格大于当前单元格，在本示例中只能访问 1 个单元格。 
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 输入：mat = [[3,1,6],[-9,5,7]]
 * 输出：4
 * 解释：上图展示了从第 2 行、第 1 列的单元格开始，可以访问 4 个单元格。可以证明，无论从哪个单元格开始，最多只能访问 4 个单元格，因此答案是 4
 * 。  
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == mat.length 
 * n == mat[i].length 
 * 1 <= m, n <= 10^5
 * 1 <= m * n <= 10^5
 * -10^5 <= mat[i][j] <= 10^5
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
    int maxIncreasingCells(vector<vector<int>>& mat) {
        return 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[3,1],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,1,6],[-9,5,7]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,2,6],[-9,1,7]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,4,5],
    [2,6,7],
    [4,1,8]]\n
// @lcpr case=end

// @lcpr case=start
// [[5,4,3],
    [6,4,2],
    [4,8,1]]\n
// @lcpr case=end

 */

