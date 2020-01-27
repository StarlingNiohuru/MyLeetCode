#include <vector>

using namespace std;

// dp iteration. dp[i][j] represents the max side length of all '1' square whose right bottom is matrix[i][j]. we have:
// dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1 when d[i][j]=='1' and i>0 and j>0. The answer is
// max((list(dp[i][j]))^2). Time complexity is O(m*n). Space complexity is O(m*n), which can be optimized to O(n).
class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        if (matrix.empty()) return 0;
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) dp[i][j] = 1;
                    else dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    res = max(res, dp[i][j]);
                }
        res = res * res;
        return res;
    }
};