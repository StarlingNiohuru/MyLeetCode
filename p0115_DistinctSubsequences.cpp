#include <vector>

using namespace std;

// dp iteration. dp[i][j] represents the number of distinct subsequences of s[0,j)==t[0,i). We have:
// If t[i - 1] == s[j - 1], dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1]; If t[i - 1] != s[j - 1], dp[i][j] = dp[i][j - 1].
// dp[m][n] is the answer. Time complexity is O(m*n). Space complexity is O(m*n), which also can be optimized to O(n).
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.size(), n = s.size();
        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++) {
                if (i == 0) dp[i][j] = 1;
                else if (j == 0) dp[i][j] = 0;
                else if (t[i - 1] == s[j - 1]) dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
                else dp[i][j] = dp[i][j - 1];
            }
        return dp[m][n];
    }
};