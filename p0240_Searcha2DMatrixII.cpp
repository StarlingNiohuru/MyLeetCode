#include <vector>

using namespace std;

// Choose the left bottom element matrix[m-1][0] at first. If matrix[i][j] < target, move upward; If < , move right;
// until find the target or hit border. Time complexity is O(log(m+n)).
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int i = matrix.size() - 1, j = 0;
        while (i >= 0 && j < matrix[0].size()) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) j++;
            else i--;
        }
        return false;
    }
};