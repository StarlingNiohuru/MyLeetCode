#include <vector>

using namespace std;

// Attention: This problem can't be split into 2 steps of 2D-dp problem each otherwise you will get a wrong answer. We
// have to consider it as a whole. Actually this problem is equal to two persons walking from (0,0) to (n-1,n-1)
// respectively. Given a state when p1 is standing in (i1,j1) and p2 is at (i2,j2). We find i1 + j1 = i2 + j2 = k. So
// we can use dp[i1][i2][k] to represent this state. Then we have: dp[i1][i2][k] = grid[i1][k - i1] + grid[i2][k - i2] +
//  + max(dp[i1][i2][k - 1], dp[i1 - 1][i2][k - 1], dp[i1][i2 - 1][k - 1], dp[i1 - 1][i2 - 1][k - 1]).
// dp[n - 1][n - 1][2 * n - 2] is the answer. Time complexity is O(n^3). Space complexity is O(n^3), which actually can
// be optimized to O(n^2).
class Solution {
public:
    int cherryPickup(vector<vector<int>> &grid) {
        int n = grid.size(), cherries;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2 * n - 1, -1)));
        dp[0][0][0] = grid[0][0];
        for (int k = 1; k < 2 * n - 1; k++)
            for (int i1 = max(0, k - n + 1); i1 <= min(k, n - 1); i1++)
                for (int i2 = max(0, k - n + 1); i2 <= min(k, n - 1); i2++) {
                    if (grid[i1][k - i1] == -1 || grid[i2][k - i2] == -1) continue;
                    cherries = dp[i1][i2][k - 1];
                    if (i1 > 0) cherries = max(cherries, dp[i1 - 1][i2][k - 1]);
                    if (i2 > 0) cherries = max(cherries, dp[i1][i2 - 1][k - 1]);
                    if (i1 > 0 && i2 > 0) cherries = max(cherries, dp[i1 - 1][i2 - 1][k - 1]);
                    if (cherries < 0) continue;
                    cherries += (i1 != i2) ? (grid[i1][k - i1] + grid[i2][k - i2]) : grid[i1][k - i1];
                    dp[i1][i2][k] = cherries;
                }
        return max(0, dp[n - 1][n - 1][2 * n - 2]);
    }
};