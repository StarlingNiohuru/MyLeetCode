#include <vector>

using namespace std;

// dp iteration. dp[n] represents the number of unique BSTs with (1-n) n nodes. We have:
// dp[i] = sum(dp[j - 1] * dp[i - j]) where j is from 1 to n. dp[n] is the answer.
// Time complexity is O(n^2). Space complexity is O(n).
class Solution {
public:
    int numTrees(int n) {
        if (n == 0) return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= i; j++)
                dp[i] += dp[j - 1] * dp[i - j];
        return dp[n];
    }
};
