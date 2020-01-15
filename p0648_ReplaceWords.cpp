#include <cstring>
#include <vector>

using namespace std;

// Trie with isEnd. For each word, we can stop searching and adding new character to result when TrieNode->isEnd=true.
// Time complexity is O(n) where n is the length of the sentence.
struct TrieNode {
    bool isEnd;
    TrieNode *next[26]{};

    TrieNode() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    };
};

class Solution {
private:
    TrieNode *root;

    void insert(string word) {
        TrieNode *node = root;
        for (char c:word) {
            if (node->next[c - 'a'] == nullptr) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }

public:
    string replaceWords(vector<string> &dict, string sentence) {
        string res;
        root = new TrieNode();
        for (string word:dict) insert(word);
        TrieNode *node = root;
        bool isPrefixFound = false;
        for (char c:sentence) {
            if (c == ' ') {
                node = root;
                isPrefixFound = false;
                res += c;
                continue;
            }
            if (!isPrefixFound) {
                res += c;
                if (node) {
                    node = node->next[c - 'a'];
                    if (node && node->isEnd) isPrefixFound = true;
                }
            }
        }
        return res;
    }
};