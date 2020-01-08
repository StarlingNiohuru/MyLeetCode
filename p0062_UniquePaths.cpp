#include <vector>

using namespace std;

// dp iteration. dp[i][j] represents all the ways to position (i,j). We can get: dp[i][j] = dp[i][j - 1] + dp[i - 1][j]
// when i!=1 and j!=1. dp[m-1][n-1] is the answer. Time complexity is O(n^2). Space complexity is O(n^2), which actually
// can be optimized to O(n).
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        return dp[m - 1][n - 1];
    }
};
