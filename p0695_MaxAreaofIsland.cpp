#include <vector>

using namespace std;

// dfs backtracking. similar to p0130 and p0200. Time complexity is O(m*n). Space complexity is O(1).
class Solution {
private:
    int m, n;
    vector<vector<int>> directions = {{0,  1},
                                      {1,  0},
                                      {0,  -1},
                                      {-1, 0}};

    void backtrack(vector<vector<int>> &grid, int &count, int i, int j) {
        if (grid[i][j] == 0) return;
        else grid[i][j] = 0;
        count++;
        int x, y;
        for (vector<int> d:directions) {
            x = i + d[0];
            y = j + d[1];
            if (x >= 0 && x < m && y >= 0 && y < n)
                backtrack(grid, count, x, y);
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        if (grid.empty()) return 0;
        int res = 0, count;
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    count = 0;
                    backtrack(grid, count, i, j);
                    res = max(res, count);
                }
        return res;
    }
};