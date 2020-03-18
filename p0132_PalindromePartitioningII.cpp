#include <vector>

using namespace std;

// dp iteration. dp[i] represents the min cut of s[0,i]. We have: dp[i] = min(dp[j] + 1) where 0<j<i when
// s[j+1,i] is palindrome. dp[n-1] is the answer. Time complexity is O(n^3). Space complexity is O(n).
class Solution {
private:
    bool isPalindrome(string s) {
        if (s.empty()) return false;
        int start = 0, stop = s.size() - 1;
        while (start <= stop) if (s[start++] != s[stop--]) return false;
        return true;
    }

public:
    int minCut(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
            if (!isPalindrome(s.substr(0, i + 1))) {
                dp[i] = INT32_MAX;
                for (int j = 0; j < i; j++)
                    if (isPalindrome(s.substr(j + 1, i - j)))
                        dp[i] = min(dp[i], dp[j] + 1);
            }
        return dp[n - 1];
    }
};

