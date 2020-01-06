#include <vector>

using namespace std;

// similar to p0054. Change direction after [1,1,2,2,3,3...] steps. Time complexity is O(max(R,C)^2).
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        vector<vector<int>> directions = {{0,  1},
                                          {1,  0},
                                          {0,  -1},
                                          {-1, 0}};
        int x = r0, y = c0, d = 0;
        for (int i = 0; i < R * C; d++) {
            for (int j = 0; j < (d + 2) / 2; j++) {
                if (0 <= x && x < R && 0 <= y && y < C) {
                    res.push_back({x, y});
                    i++;
                }
                x += directions[d % 4][0];
                y += directions[d % 4][1];
            }
        }
        return res;
    }
};