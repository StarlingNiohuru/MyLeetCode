#include <vector>

using namespace std;

// We need to find the longest common subsequence(lcs) of the 2 words then we can get our answer = m + n -2*lcs where
// m,n is the length of the 2 words each. dp[i][j] represents lcs of word1[0,i] and word2[0,j]. We can have:
// dp[i][j] = dp[i - 1][j - 1] + 1 when word1[i] = word2[j]. And dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
// when word1[i]!= word2[j]. Our answer is m + n - 2 * dp[m - 1][n - 1]. Time complexity is O(m*n), space complexity is
// O(m*n), which actually can be optimized to O(n).
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if (word1.empty() || word2.empty()) return max(m, n);
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (word1[i] == word2[j]) dp[i][j] = (i > 0 && j > 0) ? (dp[i - 1][j - 1] + 1) : 1;
                else if (i > 0 && j > 0) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                else if (i > 0) dp[i][j] = dp[i - 1][j];
                else if (j > 0) dp[i][j] = dp[i][j - 1];
            }
        return m + n - 2 * dp[m - 1][n - 1];
    }
};