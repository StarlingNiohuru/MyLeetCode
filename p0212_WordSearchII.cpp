#include <cstring>
#include <vector>

using namespace std;

// dfs backtracking and trie. but we don't need whole functions like search() and startsWith() in p0208. So we just use
// TrieNode in this problem. Time complexity is O(m*n*(4^(w*l))) where w is the number of words and l is the average
// length of the words.
struct TrieNode {
    bool isEnd;
    TrieNode *next[26]{};

    TrieNode() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    };
};

class Solution {
    int m, n;
    vector<string> res = {};
    vector<vector<int>> directions = {{0,  1},
                                      {1,  0},
                                      {0,  -1},
                                      {-1, 0}};
private:
    TrieNode *buildTrie(vector<string> words) {
        TrieNode *root = new TrieNode();
        for (string word : words) {
            TrieNode *p = root;
            for (char c : word) {
                if (p->next[c - 'a'] == nullptr) p->next[c - 'a'] = new TrieNode();
                p = p->next[c - 'a'];
            }
            p->isEnd = true;
        }
        return root;
    }

private:
    void backtrack(vector<vector<char>> &board, TrieNode *node, string prefix, int i, int j) {
        char temp = board[i][j];
        prefix += temp;
        node = node->next[temp - 'a'];
        if (node == nullptr) return;
        if (node->isEnd) {
            res.push_back(prefix);
            node->isEnd = false; // eliminate duplicate
        }
        board[i][j] = '#';
        int x, y;
        for (vector<int> d:directions) {
            x = i + d[0];
            y = j + d[1];
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] != '#')
                backtrack(board, node, prefix, x, y);
        }
        board[i][j] = temp;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        if (board.empty()) return res;
        TrieNode *root = buildTrie(words);
        string prefix;
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                backtrack(board, root, prefix, i, j);
        return res;
    }
};