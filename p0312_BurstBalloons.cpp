#include <vector>

using namespace std;

// dp iteration. First we add 2 1s at both side of nums[n-1] as balloon[n+1]. dp[i][j] represents the max coins of
// balloons(i,j) (not include i and j). Then we have: dp[i][j] = max(dp[i][k] + dp[k][j] + balloons[i] * balloons[k] *
// balloons[j]) where k is the last balloon burst between i and j so at last the balloon k must be adjacent to i and j.
// dp[0][n+1] is the answer. Time complexity is O(n^3) and Space complexity is O(n^2).
class Solution {
public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        vector<int> balloons(n + 2, 1);
        for (int i = 1; i <= n; i++) balloons[i] = nums[i - 1];
        for (int i = n; i >= 0; i--) // we scan the dp table from bottom to top,from left to right.
            for (int j = i + 1; j <= n + 1; j++)
                for (int k = i + 1; k < j; k++)
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + balloons[i] * balloons[k] * balloons[j]);
        return dp[0][n + 1];
    }
};