#include <vector>

using namespace std;

// Backtracking. Pseudo code is below:
//    if (board[row][col] == '.')
//        for (k = 0; k < 9; k++)
//            if (couldPlace(k, row, col)) //eliminate digits which exist in recent row, col and box
//                placeNumber(k, row, col);
//                placeNextNumbers(row, col); //find the next position and backtrack. if it's the last,set isSolved=true
//                if (!isSolved) removeNumber(k, row, col);
//    else placeNextNumbers(row, col);
class Solution {
private:
    void backtrack(vector<vector<int>> &rows, vector<vector<int>> &columns, vector<vector<int>> &boxes,
                   vector<vector<char>> &board, int i, int j, bool &isSolved) {
        if (board[i][j] == '.') {
            int b = (i / 3) * 3 + j / 3;
            for (int k = 0; k < 9; k++) {
                if (rows[i][k] + columns[j][k] + boxes[b][k] == 0) {
                    rows[i][k]++;
                    columns[j][k]++;
                    boxes[b][k]++;
                    board[i][j] = k + '1';
                    if (i == 8 && j == 8) isSolved = true;
                    else if (j == 8) backtrack(rows, columns, boxes, board, i + 1, 0, isSolved);
                    else backtrack(rows, columns, boxes, board, i, j + 1, isSolved);
                    if (!isSolved) {
                        rows[i][k]--;
                        columns[j][k]--;
                        boxes[b][k]--;
                        board[i][j] = '.';
                    }
                }
            }
        } else if (i == 8 && j == 8) isSolved = true;
        else if (j == 8) backtrack(rows, columns, boxes, board, i + 1, 0, isSolved);
        else backtrack(rows, columns, boxes, board, i, j + 1, isSolved);
    }

public:
    void solveSudoku(vector<vector<char>> &board) {
        vector<vector<int>> rows(9, vector<int>(9, 0));
        vector<vector<int>> columns(9, vector<int>(9, 0));
        vector<vector<int>> boxes(9, vector<int>(9, 0));
        int num, b;
        char digit;
        bool isSolved = false;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                digit = board[i][j];
                if (digit != '.') {
                    num = digit - '1';
                    b = (i / 3) * 3 + j / 3;
                    rows[i][num] += 1;
                    columns[j][num] += 1;
                    boxes[b][num] += 1;
                }
            }
        }
        backtrack(rows, columns, boxes, board, 0, 0, isSolved);
    }
};