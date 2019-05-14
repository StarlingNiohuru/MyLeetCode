#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
//        '*' is relatively hard to handle
//        using dynamic programming,dp[i][j] means if p[j:] match s[i:],from back to front,the final answer equal to dp[0][0]
//        isFirstMatch means if the first characters of s and p match each other
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[s.size()][p.size()] = true;
        for (int i = s.size(); i >= 0; i--) {
            for (int j = p.size() - 1; j >= 0; j--) {
                bool isFirstMatch = i < s.size() && (p[j] == s[i] || p[j] == '.');
                if (j < p.size() - 1 && p[j + 1] == '*') { dp[i][j] = dp[i][j + 2] || (isFirstMatch && dp[i + 1][j]); }
                else { dp[i][j] = isFirstMatch && dp[i + 1][j + 1]; }
            }
        }
        return dp[0][0];
    }
};