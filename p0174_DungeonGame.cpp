#include <vector>

using namespace std;

// This problem is slightly different from p0062-p0064. We have to solve it by dp iteration from bottom to top.
// Let dp[i][j] represent the minimum need HP from (i,j) to (m-1,n-1). So dp[0][0] is the answer. We can have:
// dp[i][j] = max(min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j], 1) when i!=m-1 and j!=n-1.
// Time complexity is O(m*n). Space complexity is O(m*n), which actually can be optimized to O(n).
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        if (dungeon.empty() || dungeon[0].empty()) return 1;
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = m - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1) dp[i][j] = (j < n - 1) ? dp[i][j + 1] : 1;
                else dp[i][j] = (j < n - 1) ? min(dp[i][j + 1], dp[i + 1][j]) : dp[i + 1][j];
                dp[i][j] = max(dp[i][j] - dungeon[i][j], 1);
            }
        return dp[0][0];
    }
};