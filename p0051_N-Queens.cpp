#include <vector>

using namespace std;

// Backtracking. Because we need to put n queens on n*n board, every row must have a queen. We can try one queen's
// position row-by-row and in each row we traverse n cols with eliminating invalid places.
// Time complexity is O(n!) and space complexity is O(n2).
class Solution {
private:
    bool couldPlace(vector<string> &board, int n, int row, int col) {
        for (int j = 0; j < row; j++) if (board[j][col] == 'Q') return false;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) if (board[i][j] == 'Q') return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) if (board[i][j] == 'Q') return false;
        return true;
    }

private:
    void backtrack(vector<vector<string>> &res, vector<string> &board, int n, int row) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (couldPlace(board, n, row, col)) {
                board[row][col] = 'Q';
                backtrack(res, board, n, row + 1);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        backtrack(res, board, n, 0);
        return res;
    }
};
