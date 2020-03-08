#include <vector>

using namespace std;

// similar to p0123. dp iteration. hold[i][j], sold[i][j] represent max profit on i-th day after buying j times. We have:
// hold[i][j] = max(hold[i - 1][j], sold[i - 1][j] - prices[i]);
// sold[i][j] = max(sold[i - 1][j], hold[i - 1][j - 1] + prices[i]);
// max(0, sold[n - 1]) is the answer. Notice when k*2>n ,this problem is equal to an p0122. For avoiding Memory Limit
// Exceeded we use the greedy way. Time complexity is O(n*k), space complexity is O(n*k), which can be optimized to O(k).
class Solution {
private:
    int maxProfitUnlimited(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++)
            if (prices[i] > prices[i - 1])
                res += prices[i] - prices[i - 1];
        return res;
    }

public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size(), res = 0;
        if (n == 0) return 0;
        if (k * 2 > n) return maxProfitUnlimited(prices);
        vector<vector<int>> hold(n, vector<int>(k + 1, 0));
        vector<vector<int>> sold(n, vector<int>(k + 1, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= k; j++) {
                if (i == 0) hold[0][j] = -prices[0];
                else if (j == 0) hold[i][0] = max(hold[i - 1][0], -prices[i]);
                else {
                    hold[i][j] = max(hold[i - 1][j], sold[i - 1][j] - prices[i]);
                    sold[i][j] = max(sold[i - 1][j], hold[i - 1][j - 1] + prices[i]);
                }
            }
        for (int s:sold[n - 1]) res = max(res, s);
        return res;
    }
};