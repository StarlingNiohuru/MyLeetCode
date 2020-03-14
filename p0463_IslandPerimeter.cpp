#include <vector>

using namespace std;

// Check how many '0's or boundaries every '1' has. Time complexity is O(m*n). Space complexity is O(1).
class Solution {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        if (grid.empty()) return 0;
        int res = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    if (i == 0 || grid[i - 1][j] == 0) res++;
                    if (i == m - 1 || grid[i + 1][j] == 0) res++;
                    if (j == 0 || grid[i][j - 1] == 0) res++;
                    if (j == n - 1 || grid[i][j + 1] == 0) res++;
                }
        return res;
    }
};