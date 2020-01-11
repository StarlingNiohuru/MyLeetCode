#include <vector>

using namespace std;

// dfs backtracking with a visited mask and emptyCount. Time complexity is O(4^(m*n)), space complexity is O(m*n).
class Solution {
    int res = 0;
    int m, n;
    int visitCount = 0, emptyCount = 0;
    vector<vector<int>> directions = {{0,  1},
                                      {1,  0},
                                      {0,  -1},
                                      {-1, 0}};
private:
    void backtrack(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j) {
        visited[i][j] = true;
        visitCount++;
        if (grid[i][j] == 2) {
            if (visitCount == emptyCount) res += 1;
            visited[i][j] = false;
            visitCount--;
            return;
        }
        int x, y;
        for (vector<int> d:directions) {
            x = i + d[0];
            y = j + d[1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != -1 && !visited[x][y])
                backtrack(grid, visited, x, y);
        }
        visited[i][j] = false;
        visitCount--;
    }

public:
    int uniquePathsIII(vector<vector<int>> &grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int x = 0, y = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) x = i, y = j;
                if (grid[i][j] != -1) emptyCount++;
            }
        backtrack(grid, visited, x, y);
        return res;
    }
};