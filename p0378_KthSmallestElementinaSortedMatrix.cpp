#include <vector>
#include <utility>
#include <queue>

using namespace std;

// Use a heap.similar to p0373. Time complexity is O(k*log(n)). But slow.
class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int res;
        int n = matrix.size();
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> pq;
        for (int i = 0; i < n && i < k; i++) pq.push({matrix[i][0], {i, 0}});
        while (k > 0 && !pq.empty()) {
            auto tmp = pq.top();
            int x = tmp.second[0], y = tmp.second[1];
            res = matrix[x][y];
            pq.pop();
            k--;
            if (y < n - 1) pq.push({matrix[x][y + 1], {x, y + 1}});
        }
        return res;
    }
};