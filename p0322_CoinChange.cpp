#include <vector>

using namespace std;

// dp iteration. dp[i] represents the fewest number of coins that can make up amount i. We can have:
// dp[i] = min(dp[i-c]) + 1 where c is in coins list and i-c>0. when dp[amount] <= amount, dp[amount] is the answer.
// Time complexity is O(n*m) where n is amount and m is length of coins list. Space complexity is O(n).
class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
            for (int coin : coins)
                if (i >= coin) dp[i] = min(dp[i], dp[i - coin] + 1);
        return dp[amount] > amount ? -1 : dp[amount];
    }
};