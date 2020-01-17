#include <vector>

using namespace std;

// dp iteration. dp[i] represents the min cost to reach i-th step. We can have:
// dp[i] = min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2]). Notice that there is one more step on the top so
// answer is dp[n] (not dp[n-1]) where n is length of cost. Time complexity is O(n).
class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; i++)
            dp[i] = min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2]);
        return dp[n];
    }
};

