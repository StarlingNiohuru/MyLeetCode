#include <vector>

using namespace std;

//dp iteration. dp[i] = min(dp[i - 1*1], dp[i - 2*2], dp[i - 3*3],...,dp[i - j*j]) + 1 (j^2<= i)
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i < n + 1; i++) {
            dp[i] = dp[i - 1] + 1;
            for (int j = 1; j * j <= i; j++)
                dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
        return dp[n];
    }
};