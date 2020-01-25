#include <vector>

using namespace std;

// Use 2 numbers to represent 2 states: 3 means 1->0; 2 means 0->1. Time complexity is O(m*n). Space complexity is O(1).
class Solution {
private:
    int liveNeighbors(vector<vector<int>> &board, int m, int n, int i, int j) {
        int count = 0;
        for (int k = i - 1; k <= i + 1; k++)
            for (int l = j - 1; l <= j + 1; l++) {
                if (k == i && l == j) continue;
                if (k >= 0 && k < m && l >= 0 && l < n && board[k][l] % 2 == 1) count++;
            }
        return count;
    }

public:
    void gameOfLife(vector<vector<int>> &board) {
        if (board.empty()) return;
        int m = board.size(), n = board[0].size(), count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                count = liveNeighbors(board, m, n, i, j);
                if (board[i][j] == 1 && (count < 2 || count > 3)) board[i][j] = 3;
                else if (board[i][j] == 0 && count == 3) board[i][j] = 2;
            }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 3) board[i][j] = 0;
                else if (board[i][j] == 2) board[i][j] = 1;
            }
    }
};