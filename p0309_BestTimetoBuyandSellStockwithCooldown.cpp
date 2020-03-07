#include <vector>

using namespace std;

// similar to p0714. dp iteration. dp[i][j] represents the max profit of the i-th day. j means hold or hold stock. We have:
// dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]); dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]).
// dp[n - 1][0] is the answer. Time complexity is O(n), space complexity is O(n), which can be optimized to O(1).
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        if (n > 1) {
            dp[1][0] = max(0, -prices[0] + prices[1]);
            dp[1][1] = max(-prices[0], -prices[1]);
        }
        for (int i = 2; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};
