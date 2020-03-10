#include <unordered_set>
#include <queue>

using namespace std;

// bfs graph search. Every step check whether every word is equal to endWord. If not, comparing wordList, push all the
// similar words (for example "hit" and ["hot","cot","hat"...], similar words are "hot" and "hat" ) into queue for
// next step. Record the number of level until finding endWord otherwise reset it to 0 after the queue is empty.
// Time complexity is O(m*n) and space complexity is O(m*n) where m is the length of beginWord and n is the one of wordList.
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        int res = 0, count;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            res++;
            count = q.size();
            for (int i = 0; i < count; i++) {
                string word = q.front();
                q.pop();
                if (word == endWord) return res;
                wordSet.erase(word);
                for (int j = 0; j < word.size(); j++) {
                    string s = word;
                    for (int k = 0; k < 26; k++) {
                        s[j] = 'a' + k;
                        if (wordSet.count(s)) q.push(s);
                    }
                }
            }
        }
        return 0;
    }
};