#include <cstring>

using namespace std;

// Trie and dfs backtracking when meeting '.'.Time complexity of addWord() is O(m) where m is the length of the word.
// Time complexity of search() is O(t) where t is the total number of characters in the trie.
class WordDictionary {
private:
    bool isEnd;
    WordDictionary *next[26]{};
private:
    void backtrack(WordDictionary *node, string &word, bool &res, int wordIndex) {
        for (int i = wordIndex; i < word.size(); i++) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; j++) {
                    if (node->next[j]) backtrack(node->next[j], word, res, i + 1);
                    if (res) return;
                }
                return;
            } else {
                node = node->next[word[i] - 'a'];
                if (node == nullptr) return;
            }
        }
        res = node->isEnd;
    }

public:
    WordDictionary() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }

    void addWord(string word) {
        WordDictionary *node = this;
        for (char c:word) {
            if (node->next[c - 'a'] == nullptr) node->next[c - 'a'] = new WordDictionary();
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        bool res = false;
        WordDictionary *node = this;
        backtrack(node, word, res, 0);
        return res;
    }
};