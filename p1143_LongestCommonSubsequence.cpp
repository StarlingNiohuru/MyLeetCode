#include <vector>

using namespace std;

// dp iteration. similar to p0583. Time complexity is O(m*n), space complexity is O(m*n),
// which actually can be optimized to O(n).
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.empty() || text2.empty()) return 0;
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) dp[i][j] = (text1[i] == text2[j]) ? 1 : 0;
                else if (i == 0) dp[i][j] = (text1[i] == text2[j]) ? 1 : dp[i][j - 1];
                else if (j == 0) dp[i][j] = (text1[i] == text2[j]) ? 1 : dp[i - 1][j];
                else dp[i][j] = (text1[i] == text2[j]) ? (dp[i - 1][j - 1] + 1) : max(dp[i - 1][j], dp[i][j - 1]);
            }
        return dp[m - 1][n - 1];
    }
};