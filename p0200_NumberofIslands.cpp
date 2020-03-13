#include <vector>

using namespace std;

// dfs backtracking. similar to p0130. Traverse the grid. When meeting '1', we add 1 to result and fill all the adjacent
// '1's with '0'. Repeat the process. Time complexity is O(m*n). Space complexity is O(1).
class Solution {
private:
    int m, n;
    vector<vector<int>> directions = {{0,  1},
                                      {1,  0},
                                      {0,  -1},
                                      {-1, 0}};

    void backtrack(vector<vector<char>> &grid, int i, int j) {
        if (grid[i][j] == '0') return;
        else grid[i][j] = '0';
        int x, y;
        for (vector<int> d:directions) {
            x = i + d[0];
            y = j + d[1];
            if (x >= 0 && x < m && y >= 0 && y < n)
                backtrack(grid, x, y);
        }
    }

public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty()) return 0;
        int res = 0;
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1') {
                    res++;
                    backtrack(grid, i, j);
                }
        return res;
    }
};