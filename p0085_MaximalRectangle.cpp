#include <vector>
#include <stack>

using namespace std;

// Transfer this problem to rect histogram as p0084. Keep a matrix heights[m][n+1]. When matrix[i][j] == '1' and i>0,
// heights[i][j] = heights[i - 1][j] + 1. Then for every row, use p0084's method to find the max rectangle. The final
// answer is the maximum. Time complexity is O(m*n).Space complexity is O(m*n), which can be optimized to O(m).
class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> heights(m, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == '1') heights[i][j] = (i > 0) ? (heights[i - 1][j] + 1) : 1;
            heights[i][n] = 0;
        }
        stack<int> stk;
        int res = 0, temp;
        for (int i = 0; i < m; i++)
            for (int j = 0; j <= n; j++) {
                while (!stk.empty() && heights[i][j] <= heights[i][stk.top()]) {
                    temp = stk.top();
                    stk.pop();
                    res = max(res, heights[i][temp] * (stk.empty() ? j : (j - stk.top() - 1)));
                }
                if (j < n) stk.push(j);
            }
        return res;
    }
};