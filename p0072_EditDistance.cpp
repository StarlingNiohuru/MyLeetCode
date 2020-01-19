#include <vector>

using namespace std;

// dp iteration. similar to p0712. dp[i][j] represents edit distance of s1[0,i) and s2[0,j) which don't include word1[i]
// and word2[j].Then dp[m][n] is the answer. We have:
// dp[i][j] = min(dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i - 1][j - 1]); when word1[i - 1] == word2[j - 1];
// dp[i][j] = min(dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1); when word1[i - 1] != word2[j - 1];
// Time complexity is O(m*n), space complexity is O(m*n).
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++) {
                if (i == 0 && j == 0) dp[i][j] = 0;
                else if (i == 0) dp[i][j] = j;
                else if (j == 0) dp[i][j] = i;
                else
                    dp[i][j] = min(min(dp[i][j - 1] + 1, dp[i - 1][j] + 1),
                                   (word1[i - 1] == word2[j - 1]) ? dp[i - 1][j - 1] : (dp[i - 1][j - 1] + 1));
            }
        return dp[m][n];
    }
};