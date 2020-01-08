#include <vector>

using namespace std;

// dp iteration. dp[i][j] represents the min sum from (0,0) to (i,j). dp[m-1][n-1] is the answer.
// We have: dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j], when i!=1 and j!=1.
// Time complexity is O(m*n). Space complexity is O(m*n), which actually can be optimized to O(n).
class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (i == 0) dp[i][j] = (j > 0) ? dp[i][j - 1] : 0;
                else dp[i][j] = (j > 0) ? min(dp[i][j - 1], dp[i - 1][j]) : dp[i - 1][j];
                dp[i][j] += grid[i][j];
            }
        return dp[m - 1][n - 1];
    }
};
