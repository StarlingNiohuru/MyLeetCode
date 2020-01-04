#include <vector>

using namespace std;

// Almost the same as p0051.
class Solution {
private:
    bool couldPlace(vector<vector<bool>> &board, int n, int row, int col) {
        for (int j = 0; j < row; j++) if (board[j][col]) return false;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) if (board[i][j]) return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) if (board[i][j]) return false;
        return true;
    }

private:
    void backtrack(int &res, vector<vector<bool>> &board, int n, int row) {
        if (row == n) {
            res++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (couldPlace(board, n, row, col)) {
                board[row][col] = true;
                backtrack(res, board, n, row + 1);
                board[row][col] = false;
            }
        }
    }

public:
    int totalNQueens(int n) {
        int res = 0;
        vector<vector<bool>> board(n, vector<bool>(n, false));
        backtrack(res, board, n, 0);
        return res;
    }
};