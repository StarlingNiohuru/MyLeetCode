#include <vector>
#include <unordered_set>

using namespace std;

// related to p0139. dp iteration. dp[i] represents the list of sentences corresponding to s[0,i) is in wordDict.
// We have: To every j in [0,i), if we find a j satisfies dp[j] not empty and s[j,i) in wordDict, dp[i] is
// list(dp[j]+s[j,i)) dp[n] is the answer. For avoiding Time Limit Exceeded, we check s first by p0139's method.
// Time complexity is O(n^3). Space complexity is O(n^2).
class Solution {
private:
    bool wordBreak1(string s, vector<string> &wordDict) {
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

public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> wordSet;
        for (string word: wordDict) wordSet.insert(word);
        int n = s.size();
        if (!wordBreak1(s, wordDict)) return {};
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++)
                if (!dp[j].empty() && wordSet.count(s.substr(j, i - j)))
                    for (string x:dp[j])
                        dp[i].push_back((x.empty() ? "" : (x + " ")) + s.substr(j, i - j));
        }
        return dp[n];
    }
};