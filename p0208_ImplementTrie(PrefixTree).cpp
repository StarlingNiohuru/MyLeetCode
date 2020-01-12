#include <cstring>

using namespace std;

// Every node has 26 children representing next character. Root node is always empty. Time complexity of insert() is
// O(m) where m is the length of the word. Similarly time complexity of search() and startsWith() are O(m) too.
class Trie {
private:
    bool isEnd;
    Trie *next[26]{};
public:
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next)); // assign 26 children with NULL
    }

    void insert(string word) {
        Trie *node = this;
        for (char c:word) {
            if (node->next[c - 'a'] == nullptr) node->next[c - 'a'] = new Trie();
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie *node = this;
        for (char c:word) {
            node = node->next[c - 'a'];
            if (node == nullptr) return false;
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        Trie *node = this;
        for (char c:prefix) {
            node = node->next[c - 'a'];
            if (node == nullptr) return false;
        }
        return true;
    }
};