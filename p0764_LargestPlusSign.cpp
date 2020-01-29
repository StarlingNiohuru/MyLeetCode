#include <vector>

using namespace std;

// dp iteration. First use gird[N][N] to store every '1' with N. Then Use left[i][j] to store left arm of gird[i][j].
// right[i][j], up[i][j], down[i][j] are the same. At last for every (i,j), record every
// min(left[i][j], right[i][j], up[i][j], down[i][j], gird[i][j]) and the max one is the answer.
// Time complexity is O(N^2). Space complexity is O(N^2).
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>> &mines) {
        vector<vector<int>> grid(N, vector<int>(N, N));
        vector<vector<int>> left(N, vector<int>(N, 0));
        vector<vector<int>> right(N, vector<int>(N, 0));
        vector<vector<int>> up(N, vector<int>(N, 0));
        vector<vector<int>> down(N, vector<int>(N, 0));
        for (auto m:mines) grid[m[0]][m[1]] = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (grid[i][j] > 0) left[i][j] = (j > 0) ? (left[i][j - 1] + 1) : 1;
        for (int i = 0; i < N; i++)
            for (int j = N - 1; j >= 0; j--)
                if (grid[i][j] > 0) right[i][j] = (j < N - 1) ? (right[i][j + 1] + 1) : 1;
        for (int j = 0; j < N; j++)
            for (int i = 0; i < N; i++)
                if (grid[i][j] > 0) up[i][j] = (i > 0) ? (up[i - 1][j] + 1) : 1;
        for (int j = 0; j < N; j++)
            for (int i = N - 1; i >= 0; i--)
                if (grid[i][j] > 0) down[i][j] = (i < N - 1) ? (down[i + 1][j] + 1) : 1;
        int res = 0, temp;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                temp = min(min(min(left[i][j], right[i][j]), min(up[i][j], down[i][j])), grid[i][j]);
                res = max(res, temp);
            }
        return res;
    }
};
