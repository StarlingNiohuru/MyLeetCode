#include <cstring>
#include <vector>

using namespace std;

// Trie. We use TrieNode with weight and 27 children (one for '{' because '{' is close to z in ASCII). For example a
// word "apple", we insert "apple{apple", "pple{apple", "ple{apple", "le{apple", "e{apple", "{apple" into the Trie Tree
// with the weight. When searching a pair ("app","le"), we can use "le{app" to find the node and the weight of the node
// is just corresponding the last suitable word because we inserted the words in order. Time complexity is O(n*k^2+q*k)
// where n is the number of words, k is the longest length of the words, q is the number of queries. Space complexity
// is O(n*k^2).
struct TrieNode {
    int weight;
    TrieNode *next[27]{};

    TrieNode() {
        weight = 0;
        memset(next, 0, sizeof(next));
    };
};

class WordFilter {

private:
    TrieNode *root;

    void insert(string word, int i) {
        TrieNode *node = root;
        for (char c:word) {
            if (node->next[c - 'a'] == nullptr) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
            node->weight = i;
        }
    }

public:
    WordFilter(vector<string> &words) {
        root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            string s = word + '{' + word;
            for (int j = 0; j < word.size() + 1; j++)
                insert(s.substr(j, s.size() - j), i);
        }
    }

    int f(string prefix, string suffix) {
        TrieNode *node = root;
        for (char c:suffix + '{' + prefix) {
            node = node->next[c - 'a'];
            if (node == nullptr) return -1;
        }
        return node->weight;
    }
};