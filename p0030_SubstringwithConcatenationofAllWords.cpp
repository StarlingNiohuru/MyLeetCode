#include <vector>
#include <unordered_map>

using namespace std;

// Use 2 hash tables. wordsCount is used to record the frequency of the words list. strCount is used to record the
// frequency of strings in one window whose length = num * len (word's num and word's len).
class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        if (words.empty()) return {};
        vector<int> res;
        unordered_map<string, int> wordsCount;
        for (string word:words) wordsCount[word]++;
        int wordNum = words.size(), wordLen = words[0].size();
        for (int i = 0; i + wordLen * wordNum - 1 < s.size(); i++) {
            unordered_map<string, int> strCount;
            int j = 0;
            for (; j < wordNum; j++) {
                string str = s.substr(i + j * wordLen, wordLen);
                if (wordsCount.count(str)) {
                    strCount[str]++;
                    if (strCount[str] > wordsCount[str]) break;
                } else break;
            }
            if (j == wordNum) res.push_back(i);
        }
        return res;
    }
};