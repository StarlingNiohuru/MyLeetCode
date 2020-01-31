#include <vector>

using namespace std;

// dp iteration. dp[len][i][j] represents whether s1[i:i+len] can be transformed from s2[j,j+len]. We have:
// dp[len][i][j] = (dp[k][i][j] && dp[len - k][i + k][j + k])||(dp[k][i][j + len - k] && dp[len - k][i + k][j]).
// dp[n][0][0] is the answer.Time complexity is O(n^4). Space complexity is O(n^3).
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1.empty() && s2.empty()) return false;
        int n = s1.size();
        vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(n, vector<bool>(n, false)));
        for (int len = 1; len <= n; len++)
            for (int i = 0; i <= n - len; i++)
                for (int j = 0; j <= n - len; j++) {
                    if (len == 1) dp[len][i][j] = (s1[i] == s2[j]);
                    else {
                        for (int k = 1; k < len && !dp[len][i][j]; k++) {
                            dp[len][i][j] = dp[len][i][j] || (dp[k][i][j] && dp[len - k][i + k][j + k]);
                            dp[len][i][j] = dp[len][i][j] || (dp[k][i][j + len - k] && dp[len - k][i + k][j]);
                        }
                    }
                }
        return dp[n][0][0];
    }
};