#include <vector>

using namespace std;

// This problem is not related with binary search. Use dp instead. dp[i][j] represents the min cost guaranteeing win
// the game [i,i+1, i+2,......j-1, j]. We can pick a number k from [i,j] and divide the list into [i,k] and [k,j].
// The cost = max(dp[i][k - 1], dp[k + 1][j]).Then we can try every k from [i,j]. Then we have:
// dp[i][j] = min(k + max(dp[i][k - 1], dp[k + 1][j])) (k is from i+1 to j-1).
// Time complexity is O(n3). Space complexity is O(n2).
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int len = 1; len <= n; len++) {
            for (int i = 1; i + len <= n; i++) {
                int j = i + len;
                dp[i][j] = INT32_MAX;
                for (int k = i + (j - i) / 2; k < j; k++) // Don't need to scan k from i+1 to j-1. from mid instead
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
            }
        }
        return dp[1][n];
    }
};