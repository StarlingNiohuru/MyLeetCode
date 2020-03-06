#include <vector>

using namespace std;

// dp iteration. dp[i][j] represents the max profit of the i-th day. j means hold cash(j=0) or hold stock(j=1). We have:
// dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]); dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee).
// dp[n - 1][0] is the answer. Time complexity is O(n), space complexity is O(n), which can be optimized to O(1).
class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0] - fee;
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee);
        }
        return dp[n - 1][0];
    }
};