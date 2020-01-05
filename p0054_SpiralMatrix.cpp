#include <vector>

using namespace std;

// Use a 2D bool array to memorize the position visited and directions array to calculate next position more easily.
// Time complexity is O(m*n).
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> visited = {m, vector<bool>(n, false)};
        vector<vector<int>> directions = {{0,  1},
                                          {1,  0},
                                          {0,  -1},
                                          {-1, 0}};
        int x = 0, y = 0, d = 0, nx, ny;
        for (int i = 0; i < m * n; i++) {
            res.push_back(matrix[x][y]);
            visited[x][y] = true;
            nx = x + directions[d][0];
            ny = y + directions[d][1];
            if (0 <= nx && nx < m && 0 <= ny && ny < n && !visited[nx][ny]) {
                x = nx;
                y = ny;
            } else {
                d = (d + 1) % 4;
                x += directions[d][0];
                y += directions[d][1];
            }
        }
        return res;
    }
};