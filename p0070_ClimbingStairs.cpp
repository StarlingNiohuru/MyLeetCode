#include <vector>

using namespace std;

// dp iteration. The equation is a Fibonacci sequence satisfying dp[i] = dp[i - 1] + dp[i - 2]. Time complexity is O(n).
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n, 1);
        if (n > 1) dp[1] = 2;
        for (int i = 2; i < n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n - 1];
    }
};