#include <vector>
#include <unordered_set>

using namespace std;

// dp iteration. dp[i] represents whether s[0,i) is in wordDict. We have: To every j in [0,i), if we find a j satisfies
// dp[j]=true and s[j,i) in wordDict, dp[i]=true. Otherwise false. dp[n] is the answer.
// Time complexity is O(n^2). Space complexity is O(n).
class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> wordSet;
        for (string word: wordDict) wordSet.insert(word);
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i; j++)
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
        return dp[n];
    }
};
