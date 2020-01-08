#include <vector>

using namespace std;

// similar to p0062.Time complexity is O(m*n). Space complexity is O(m*n), which actually can be optimized to O(n).
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long>> dp(m, vector<long>(n, 1));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else if (i == 0) dp[i][j] = (j > 0) ? dp[i][j - 1] : 1;
                else dp[i][j] = (j > 0) ? dp[i][j - 1] + dp[i - 1][j] : dp[i - 1][j];
            }
        return dp[m - 1][n - 1];
    }
};