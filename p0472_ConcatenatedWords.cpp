#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// related to p0139. For avoiding Time Limit Exceeded, we sort the words list by length. Then check by wordBreak and
// put word into wordSet one by one. Time complexity is O(n^3). Space complexity is O(n).
class Solution {
private:
    bool wordBreak(string s, unordered_set<string> &wordSet) {
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
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        vector<string> res;
        auto sizeComp = [&](const string &str1, const string &str2) { return str1.size() < str2.size(); };
        sort(words.begin(), words.end(), sizeComp);
        unordered_set<string> wordSet;
        for (string word:words)
            if (!word.empty()) {
                if (wordBreak(word, wordSet)) res.push_back(word);
                wordSet.insert(word);
            }
        return res;
    }
};