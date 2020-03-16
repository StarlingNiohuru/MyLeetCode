#include <vector>

using namespace std;

// dfs backtracking with a visited mask. similar to p0733. Time complexity is O(m*n). Space complexity is O(m*n).
class Solution {
private:
    bool dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int m, int n, int i, int j, int oldColor,
             int newColor) {
        if (i >= 0 && i < m && j >= 0 && j < n && (visited[i][j] || grid[i][j] == oldColor)) {
            if (visited[i][j]) return true;
            else visited[i][j] = true;
            bool u, d, l, r;
            u = dfs(grid, visited, m, n, i - 1, j, oldColor, newColor);
            d = dfs(grid, visited, m, n, i + 1, j, oldColor, newColor);
            l = dfs(grid, visited, m, n, i, j - 1, oldColor, newColor);
            r = dfs(grid, visited, m, n, i, j + 1, oldColor, newColor);
            if (!(u && d && l && r)) grid[i][j] = newColor;
            return true;
        } else return false;
    }

public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int r0, int c0, int color) {
        if (grid.empty()) return grid;
        int m = grid.size(), n = grid[0].size(), oldColor = grid[r0][c0];
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        if (oldColor != color) dfs(grid, visited, m, n, r0, c0, oldColor, color);
        return grid;
    }
};