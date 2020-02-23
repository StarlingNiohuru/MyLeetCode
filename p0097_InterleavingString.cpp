#include <vector>

using namespace std;

// dp iteration. dp[i][j] represents whether s1[0,i) and s2[0,j) can be interleaving string of s3[0,i+j). We have:
// dp[i][j] = (dp[i][j - 1] && (s3[i + j - 1] == s2[j - 1])) || (dp[i - 1][j] && (s3[i + j - 1] == s1[i - 1])).
// dp[m][n] is the answer. Time complexity is O(m*n). Space complexity is O(m*n), which also can be optimized to O(n).
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) return false;
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++) {
                if (i == 0 && j == 0) dp[i][j] = true;
                else if (i == 0) dp[i][j] = dp[i][j - 1] && (s3[j - 1] == s2[j - 1]);
                else if (j == 0) dp[i][j] = dp[i - 1][j] && (s3[i - 1] == s1[i - 1]);
                else
                    dp[i][j] = (dp[i][j - 1] && (s3[i + j - 1] == s2[j - 1])) ||
                               (dp[i - 1][j] && (s3[i + j - 1] == s1[i - 1]));
            }
        return dp[m][n];
    }
};

