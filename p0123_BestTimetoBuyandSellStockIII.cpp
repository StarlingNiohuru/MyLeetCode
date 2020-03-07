#include <vector>

using namespace std;

// similar to p0309 v2. dp iteration. hold(n)[i], sold(n)[i] represent 4 different possible states of i-th day. We have:
// hold(n)[i] = max(hold(n)[i - 1], (i > 1) ? sold(n-1)[i - 1] - prices[i]);
// sold(n)[i] = max(sold(n)[i - 1], hold(n)[i - 1] + prices[i]).
// max(0, sold1[n - 1], sold2[n - 1]) is the answer.
// Time complexity is O(n), space complexity is O(n), which can be optimized to O(1).
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size(), res;
        if (n == 0) return 0;
        vector<int> hold1(n, -prices[0]);
        vector<int> sold1(n, INT32_MIN);
        vector<int> hold2(n, INT32_MIN);
        vector<int> sold2(n, INT32_MIN);
        for (int i = 1; i < n; i++) {
            hold1[i] = max(hold1[i - 1], -prices[i]);
            sold1[i] = max(sold1[i - 1], hold1[i - 1] + prices[i]);
            hold2[i] = max(hold2[i - 1], (i > 1) ? sold1[i - 1] - prices[i] : INT32_MIN);
            sold2[i] = max(sold2[i - 1], hold2[i - 1] + prices[i]);
        }
        res = max(sold1[n - 1], sold2[n - 1]);
        res = (res > 0) ? res : 0;
        return res;
    }
};
