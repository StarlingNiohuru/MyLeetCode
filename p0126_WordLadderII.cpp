#include <unordered_set>
#include <queue>

using namespace std;

// similar to p0127. But push whole path into queue instead. Time complexity is O(m*n) and space complexity is O(m*n)
// where m is the length of beginWord and n is the one of wordList.
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        vector<vector<string>> res;
        int ladder = 0, count;
        bool found = false;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        while (!q.empty() && !found) {
            ladder++;
            count = q.size();
            for (int i = 0; i < count; i++) {
                vector<string> path = q.front();
                string word = path.back();
                q.pop();
                if (word == endWord) {
                    found = true;
                    res.push_back(path);
                }
                wordSet.erase(word);
                for (int j = 0; j < word.size(); j++) {
                    string s = word;
                    for (int k = 0; k < 26; k++) {
                        s[j] = 'a' + k;
                        if (wordSet.count(s)) {
                            vector<string> newPath = path;
                            newPath.push_back(s);
                            q.push(newPath);
                        }
                    }
                }
            }
        }
        return res;
    }
};