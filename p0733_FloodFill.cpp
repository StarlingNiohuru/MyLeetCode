#include <vector>

using namespace std;

// dfs backtracking. Notice the case when oldColor==newColor. Time complexity is O(m*n). Space complexity is O(1).
class Solution {
private:
    void backtrack(vector<vector<int>> &image, int m, int n, int i, int j, int oldColor, int newColor) {
        if (image[i][j] == oldColor) {
            image[i][j] = newColor;
            if (i - 1 >= 0) backtrack(image, m, n, i - 1, j, oldColor, newColor);
            if (i + 1 < m) backtrack(image, m, n, i + 1, j, oldColor, newColor);
            if (j - 1 >= 0) backtrack(image, m, n, i, j - 1, oldColor, newColor);
            if (j + 1 < n) backtrack(image, m, n, i, j + 1, oldColor, newColor);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        if (image.empty()) return image;
        int m = image.size(), n = image[0].size(), oldColor = image[sr][sc];
        if (oldColor != newColor) backtrack(image, m, n, sr, sc, oldColor, newColor);
        return image;
    }
};