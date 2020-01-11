#include <vector>

using namespace std;

// dfs backtracking with a visited mask and a count. Time complexity is O(m*n*(4^k)), where k is the length of the word.
// Space complexity is O(m*n).
class Solution {
    int m, n;
    bool res = false;
    vector<vector<int>> directions = {{0,  1},
                                      {1,  0},
                                      {0,  -1},
                                      {-1, 0}};
private:
    void backtrack(vector<vector<char>> &board, vector<vector<bool>> &visited, string &word, int i, int j, int count) {
        if (board[i][j] != word[count]) return;
        if (count == word.size() - 1) {
            res = true;
            return;
        }
        visited[i][j] = true;
        int x, y;
        for (vector<int> d:directions) {
            x = i + d[0];
            y = j + d[1];
            if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y])
                backtrack(board, visited, word, x, y, count + 1);
            if (res) return;
        }
        visited[i][j] = false;
    }

public:
    bool exist(vector<vector<char>> &board, string word) {
        if (board.empty()) return res;
        m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                backtrack(board, visited, word, i, j, 0);
        return res;
    }
};