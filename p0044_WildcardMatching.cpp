#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
//        This problem is similar to No 10, Reqular Expression Matching, but '*' has different meaning.
//        Time complexity is O(M*N) ,not the best solution
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[s.size()][p.size()] = true;
        for (int i = s.size(); i >= 0; i--) {
            for (int j = p.size() - 1; j >= 0; j--) {
                bool isFirstMatch = i < s.size() && (p[j] == s[i] || p[j] == '?');
                if (p[j] == '*') { dp[i][j] = dp[i][j + 1] || (i < s.size() && dp[i + 1][j]); }
                else { dp[i][j] = isFirstMatch && dp[i + 1][j + 1]; }
            }
        }
        return dp[0][0];
    }
};