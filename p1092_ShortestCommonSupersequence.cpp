#include <vector>

using namespace std;

// dp iteration. This problem is related to p1143. First we get string lcs of str1 and str2 then we use lcs to build scs.
// Time complexity is O(m*n*min(m,n)), space complexity is O(m*n), which actually can be optimized to O(n).
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<string>> dp(m + 1, vector<string>(n + 1, ""));
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= n; j++) {
                if (i > 0 && j > 0) {
                    if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + str1[i - 1];
                    else dp[i][j] = (dp[i - 1][j].size() > dp[i][j - 1].size()) ? dp[i - 1][j] : dp[i][j - 1];
                }
            }
        string lcs = dp[m][n], res;
        for (int i = 0, j = 0, k = 0; i < m || j < n || k < lcs.size(); i++, j++, k++) {
            while (str1[i] != lcs[k]) res += str1[i++];
            while (str2[j] != lcs[k]) res += str2[j++];
            res += lcs[k];
        }
        return res;
    }
};