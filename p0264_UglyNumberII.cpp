#include <vector>

using namespace std;

//dp iteration with 3 pointers. dp[new] = min(dp[p1]*2, dp[p2]*3, dp[p3]*5)
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        int pointer1 = 0, pointer2 = 0, pointer3 = 0;
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            dp[i] = min(min(dp[pointer1] * 2, dp[pointer2] * 3), dp[pointer3] * 5);
            if (dp[i] == dp[pointer1] * 2) pointer1++;
            if (dp[i] == dp[pointer2] * 3) pointer2++;
            if (dp[i] == dp[pointer3] * 5) pointer3++;
        }
        return dp[n - 1];
    }

};