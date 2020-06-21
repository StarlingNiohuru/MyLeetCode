#include <vector>

using namespace std;

// dp iteration. dp[i][j] represents the min cost of stones[i,j] (include i and j. If stones[i,j] can't be merged into
// 1 pile, dp[i][j] represents merged as much as it can). Then we have: dp[i][j] = min(dp[i][m - 1] + dp[m][j]) +
// sum(stones[i,j]) where m is the index which divide stones[i,j] into K-1 piles(stones[i,m-1]) and 1 pile(stones[m,j]).
// dp[0][n - 1] is the answer. Time complexity is O(n^3) and Space complexity is O(n^2).
class Solution {
public:
    int mergeStones(vector<int> &stones, int K) {
        int n = stones.size();
        if ((n - 1) % (K - 1)) return -1; // if (n - 1) % (K - 1)!=0 ,it can't be divided into K piles(==merged into 1).
        vector<int> accSum;
        accSum.push_back(0);
        for (int stone:stones)
            accSum.push_back(accSum.back() + stone); // accSum[] is the accumulative sum for calculating sum[i,j]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int j = 0; j < n; j++) // we scan the dp table from left to right, from bottom to top.
            for (int i = j - K + 1; i >= 0; i--) { // j-i+1 must >= K.
                dp[i][j] = INT32_MAX;
                for (int m = j; m > i; m -= (K - 1))
                    dp[i][j] = min(dp[i][j], dp[i][m - 1] + dp[m][j]);
                if ((j - i) % (K - 1) == 0) // only let dp[i][j] + sum[i,j] when it can be divided into K piles.
                    dp[i][j] += accSum[j + 1] - accSum[i];
            }
        return dp[0][n - 1];
    }
};