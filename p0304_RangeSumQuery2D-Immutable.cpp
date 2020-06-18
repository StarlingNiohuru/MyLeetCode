#include <vector>

using namespace std;

// dp iteration. dp[i][j] represents sumRegion(0,0),(i,j)). We have: dp[i + 1][j + 1] = matrix[i][j] + dp[i][j + 1] +
// dp[i + 1][j] - dp[i][j]. Then we also have sumRegion((r1,c1),(r2,c2)) = dp[r2 + 1][c2 + 1] - dp[r2 + 1][c1] -
// dp[r1][c2 + 1] + dp[r1][c1]. Time complexity of construct() is O(m*n) and that of sumRegion() is O(1).
// Space complexity is O(m*n).
class NumMatrix {
private:
    int m, n;
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        m = matrix.size();
        n = (m > 0) ? matrix[0].size() : 0;
        dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                dp[i + 1][j + 1] = matrix[i][j] + dp[i][j + 1] + dp[i + 1][j] - dp[i][j];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row2 + 1][col1] - dp[row1][col2 + 1] + dp[row1][col1];
    }
};