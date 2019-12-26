#include <vector>

using namespace std;

// Transfer the matrix to a array and use binary search. Time complexity is O(log(m*n)).
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        int lo = 0, hi = m * n - 1, mid;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (matrix[mid / n][mid % n] == target) return true;
            else if (matrix[mid / n][mid % n] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return false;
    }
};