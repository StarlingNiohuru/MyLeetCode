#include <vector>

using namespace std;

// dp iteration. many situations need to be considered: When s[i]='*', dp[i] += dp[i - 1] * 9; when s[i-1,i]="1*",
// dp[i] += dp[i - 2] * 9; when s[i-1,i]="2*", dp[i] += dp[i - 2] * 6; when s[i-1,i]="**", dp[i] += dp[i - 2] * 15;
// when s[i-1,i]="*[0-6]", dp[i] += dp[i - 2] * 2; when s[i-1,i]="*[7-9]", dp[i] += dp[i - 2].The answer is dp[n-1].
// Time complexity is O(n). Space complexity is O(n) which actually can be optimized to O(1).
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), M = 1000000007;
        vector<long> dp(n, 0);
        if (s[0] == '0') return 0;
        else if (s[0] == '*') dp[0] = 9;
        else dp[0] = 1;
        if (n > 1) {
            if (s[1] != '0') dp[1] += 1;
            if ((s[0] == '1' || (s[0] == '2' && s[1] <= '6')) && s[1] != '*') dp[1] += 1;
            if (s[0] == '*' && s[1] == '0') dp[1] = 2;
            if (s[0] == '*' && s[1] != '*' && s[1] <= '6' && s[1] > '0') dp[1] = 9 + 2;
            if (s[0] == '*' && s[1] != '*' && s[1] > '6') dp[1] = 9 + 1;
            if (s[1] == '*')
                if (s[0] == '1') dp[1] = 9 + 9;
                else if (s[0] == '2') dp[1] = 9 + 6;
                else if (s[0] == '*') dp[1] = 9 * 9 + 9 + 6;
                else dp[1] = 9;
        }
        for (int i = 2; i < n; i++) {
            if (s[i] == '0' && s[i - 1] == '0') return 0;
            if (s[i] != '0' && s[i] != '*') dp[i] += dp[i - 1];
            if (s[i] == '*') dp[i] += dp[i - 1] * 9;
            if ((s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) && s[i] != '*') dp[i] += dp[i - 2];
            if (s[i - 1] == '1' && s[i] == '*') dp[i] += dp[i - 2] * 9;
            if (s[i - 1] == '2' && s[i] == '*') dp[i] += dp[i - 2] * 6;
            if (s[i - 1] == '*' && s[i] == '*') dp[i] += dp[i - 2] * 15;
            if (s[i - 1] == '*' && s[i] != '*' && s[i] <= '6') dp[i] += dp[i - 2] * 2;
            if (s[i - 1] == '*' && s[i] != '*' && s[i] > '6') dp[i] += dp[i - 2];
            dp[i] %= M;
        }
        return dp[n - 1];
    }
};