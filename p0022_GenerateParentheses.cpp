#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
//        dp iteration, dp[n] = ( dp[p] ) + dp[q] ; p + q = n - 1
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i; j++)
                for (string x:dp[j])
                    for (string y:dp[i - j - 1])
                        dp[i].push_back("(" + x + ")" + y);
        return dp[n];
    }
};