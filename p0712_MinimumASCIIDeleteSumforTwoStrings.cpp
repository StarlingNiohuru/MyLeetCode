#include <vector>

using namespace std;

// dp iteration. This problem is similar to p0583 but has some differences. dp[i][j] represents the min ascii sum of
// s1[0,i) and s2[0,j) which don't include s1[i] and s2[j]. Then dp[m][n] is the answer. We can have:
// dp[i][j] = dp[i - 1][j - 1] when s1[i - 1] == s2[j - 1];
// dp[i][j] = min(dp[i - 1][j] + int(s1[i - 1]), dp[i][j - 1] + int(s2[j - 1])) when s1[i - 1] != s2[j - 1].
// Time complexity is O(m*n), space complexity is O(m*n), which actually can be optimized to O(n).
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++) {
                if (i == 0 && j == 0) dp[i][j] = 0;
                else if (i == 0) dp[i][j] = dp[i][j - 1] + int(s2[j - 1]);
                else if (j == 0) dp[i][j] = dp[i - 1][j] + int(s1[i - 1]);
                else
                    dp[i][j] = (s1[i - 1] == s2[j - 1]) ? dp[i - 1][j - 1] :
                               min(dp[i - 1][j] + int(s1[i - 1]), dp[i][j - 1] + int(s2[j - 1]));
            }
        return dp[m][n];
    }
};