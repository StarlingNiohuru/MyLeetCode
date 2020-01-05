#include <vector>

using namespace std;

// similar to p0054. Time complexity is O(n2).
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        vector<vector<int>> directions = {{0,  1},
                                          {1,  0},
                                          {0,  -1},
                                          {-1, 0}};
        int x = 0, y = 0, d = 0, nx, ny;
        for (int i = 1; i <= n * n; i++) {
            res[x][y] = i;
            nx = x + directions[d][0];
            ny = y + directions[d][1];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && res[nx][ny] == 0) {
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