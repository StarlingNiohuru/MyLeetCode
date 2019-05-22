#include <queue>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>> &heightMap) {
//        use a priority_queue to record a boundary, find the min(also hMax, the max water height) of the queue and pop it,
//        update hMax if necessary, calculate and push all the neighbors into the queue
        if (heightMap.size() == 0) return 0;
        int res = 0, hMax = 0, row = heightMap.size(), col = heightMap[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> boundary;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 || i == row - 1 || j == 0 || j == col - 1) {
                    boundary.push(make_pair(heightMap[i][j], i * col + j));
                    visited[i][j] = true;
                }
            }
        }
        vector<vector<int>> neighbors = {{0,  1},
                                         {0,  -1},
                                         {1,  0},
                                         {-1, 0}};
        while (!boundary.empty()) {
            auto val = boundary.top();
            boundary.pop();
            int height = val.first, x = val.second / col, y = val.second % col;
            hMax = max(height, hMax);
            for (auto n:neighbors) {
                int x2 = x + n[0], y2 = y + n[1];
                if (x2 > 0 && x2 < row && y2 > 0 && y2 < col && !visited[x2][y2]) {
                    visited[x2][y2] = true;
                    if (heightMap[x2][y2] < hMax) res += hMax - heightMap[x2][y2];
                    boundary.push(make_pair(heightMap[x2][y2], x2 * col + y2));
                }
            }
        }
        return res;
    }
};
