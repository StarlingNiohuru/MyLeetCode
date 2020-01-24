#include <vector>

using namespace std;

//When a matrix[i][j]==0 (i>0,j>0), we can mark matrix[0][j]=0 and matrix[i][0]=0. If any matrix[0][j]==0, we mark
// firstRowZero = true. firstColZero is in the same way. Then we fill every row and col marked with 0 and at last fill
// the first row or col by firstRowZero or firstColZero. Time complexity is O(m*n). Space complexity is O(1).
class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        if (matrix.empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 0) {
                    if (i == 0) firstRowZero = true;
                    if (j == 0) firstColZero = true;
                    if (i > 0 && j > 0) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
        for (int i = 1; i < m; i++) if (matrix[i][0] == 0) for (int j = 1; j < n; j++) matrix[i][j] = 0;
        for (int j = 1; j < n; j++) if (matrix[0][j] == 0) for (int i = 1; i < m; i++) matrix[i][j] = 0;
        if (firstRowZero) for (int j = 0; j < n; j++) matrix[0][j] = 0;
        if (firstColZero) for (int i = 0; i < m; i++) matrix[i][0] = 0;
    }
};