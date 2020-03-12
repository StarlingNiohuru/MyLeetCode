#include <vector>

using namespace std;

// dfs backtracking. First we need to find out all the "O"s accessed to boundaries and change them to "X"s. Then we
// change all the rest of "O"s to "X". At last recover all the "#"s to "O"s.
// Time complexity is O(m*n). Space complexity is O(1).
class Solution {
private:
    int m, n;
    vector<vector<int>> directions = {{0,  1},
                                      {1,  0},
                                      {0,  -1},
                                      {-1, 0}};

    void backtrack(vector<vector<char>> &board, int i, int j) {
        if (board[i][j] != 'O') return;
        else board[i][j] = '#';
        int x, y;
        for (vector<int> d:directions) {
            x = i + d[0];
            y = j + d[1];
            if (x >= 0 && x < m && y >= 0 && y < n)
                backtrack(board, x, y);
        }
    }

public:
    void solve(vector<vector<char>> &board) {
        if (board.empty()) return;
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            backtrack(board, i, 0);
            backtrack(board, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            backtrack(board, 0, j);
            backtrack(board, m - 1, j);
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
    }
};