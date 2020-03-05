#include <vector>

using namespace std;

// dp iteration. dp[i][j] represents the min sum from top to triangle[i][j]. We have:
// dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j], when 0<j<i. min(dp[n-1]) is the answer.
// Time complexity is O(n^2). Space complexity is O(n^2).
class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size(), res = INT32_MAX;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++)
            for (int j = 0; j <= i; j++) {
                if (j == 0) dp[i][j] = dp[i - 1][j] + triangle[i][j];
                else if (j < i) dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
                else dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            }
        for (int k:dp[n - 1]) res = min(res, k);
        return res;
    }
};