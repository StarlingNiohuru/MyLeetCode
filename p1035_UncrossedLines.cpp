#include <vector>

using namespace std;

// dp iteration. Almost the same with p1143. Time complexity is O(m*n), space complexity is O(m*n), which actually can
// be optimized to O(n).
class Solution {
public:
    int maxUncrossedLines(vector<int> &A, vector<int> &B) {
        int m = A.size(), n = B.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++) {
                if (i > 0 && j > 0) {
                    if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                    else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        return dp[m][n];
    }
};
