#include <iostream>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int i, j, k, left, right, charNum, TOTALCHARNUM, slen;
        slen = S.size();
        if (slen == 0) { return 0; }
        TOTALCHARNUM = 4;
        long dp[slen][slen];
        // ci[4][2] is used for recording every char's left and right indexes     0:left,1:right
        int ci[TOTALCHARNUM][2];
        int ce[TOTALCHARNUM];
        for (i = slen - 1; i >= 0; i--) {
            // init ci and ce
            for (k = 0; k < TOTALCHARNUM; k++) {
                ci[k][0] = -1;
                ci[k][1] = -1;
                ce[k] = 0;
            }
            for (j = i; j < slen; j++) {
                charNum = S[j] - 'a';
                if (ci[charNum][0] == -1) { ci[charNum][0] = j; } else { ci[charNum][1] = j; }
                ce[charNum] = 1;
                if (i == j) { dp[i][j] = 2; }
                else {
                    dp[i][j] = 1;
                    for (k = 0; k < TOTALCHARNUM; k++) {
                        left = ci[k][0], right = ci[k][1];
                        if (left != -1 && right != -1) {
                            if (right - left < 2) { dp[i][j] += 1; }
                            else { dp[i][j] += dp[left + 1][right - 1]; }
                        }
                        dp[i][j] += ce[k];
                    }
                    dp[i][j] %= 1000000007;
                }
            }
        }
        return dp[0][slen - 1] - 1;
    }
};
