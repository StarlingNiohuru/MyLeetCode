#include <vector>

using namespace std;

// Use 2d-vectors instead of hash tables. Use box_index = (i / 3) * 3 + j / 3 to count boxes.
// Time complexity is O(1).
class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<vector<int>> rows(9, vector<int>(9, 0));
        vector<vector<int>> columns(9, vector<int>(9, 0));
        vector<vector<int>> boxes(9, vector<int>(9, 0));
        int num, b;
        char digit;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                digit = board[i][j];
                if (digit != '.') {
                    num = digit - '1';
                    b = (i / 3) * 3 + j / 3;
                    rows[i][num] += 1;
                    columns[j][num] += 1;
                    boxes[b][num] += 1;
                    if (rows[i][num] > 1 || columns[j][num] > 1 || boxes[b][num] > 1)
                        return false;
                }
            }
        }
        return true;
    }
};