#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// We sort the words list first and use a set to store words which could be used later. Save the longest valid word.
// Time complexity is O(n*log(n*l)) where n is the length of words list and l is the average length of a word.
class Solution {
public:
    string longestWord(vector<string> &words) {
        string res;
        sort(words.begin(), words.end());
        unordered_set<string> wordSet;
        for (string word:words) {
            if (word.size() == 1 || wordSet.count(word.substr(0, word.size() - 1))) {
                res = (word.size() > res.size()) ? word : res;
                wordSet.insert(word);
            }
        }
        return res;
    }
};