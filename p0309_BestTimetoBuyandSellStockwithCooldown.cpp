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

// dp iteration. rest[i], hold[i], sold[i] represent 3 different possible states of i-th day. We have:
// rest[i] = max(rest[i - 1], sold[i - 1]); hold[i] = max(hold[i - 1], rest[i - 1] - prices[i]); sold[i] = hold[i - 1] + prices[i].
// max(rest[n - 1], sold[n - 1]) is the answer. Time complexity is O(n), space complexity is O(n), which can be optimized to O(1).
class Solution2 {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<int> rest(n, 0);
        vector<int> hold(n, -prices[0]);
        vector<int> sold(n, INT32_MIN);
        for (int i = 1; i < n; i++) {
            rest[i] = max(rest[i - 1], sold[i - 1]);
            hold[i] = max(hold[i - 1], rest[i - 1] - prices[i]);
            sold[i] = hold[i - 1] + prices[i];
        }
        return max(rest[n - 1], sold[n - 1]);
    }
};
