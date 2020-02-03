#include <vector>

using namespace std;

// dp iteration. When s[i]!=0 dp[i]+=dp[i-1]; when 10<=s[i-1,i]<=26, dp[i]+=dp[i-2]. The answer is dp[n-1].
// Time complexity is O(n). Space complexity is O(n) which actually can be optimized to O(1).
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        if (s[0] == '0') return 0;
        else dp[0] = 1;
        if (n > 1) {
            if (s[1] != '0') dp[1] += 1;
            if (s[0] == '1' || (s[0] == '2' && s[1] <= '6')) dp[1] += 1;
        }
        for (int i = 2; i < n; i++) {
            if (s[i] == '0' && s[i - 1] == '0') return 0;
            if (s[i] != '0') dp[i] += dp[i - 1];
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) dp[i] += dp[i - 2];
        }
        return dp[n - 1];
    }
};