#include <vector>
#include <utility>
#include <queue>

using namespace std;

// Use binary search. Every step we can count how many numbers less than mid and compare count with k.
// Time complexity O(n*log(n)).
class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int lo = matrix[0][0], hi = matrix.back().back(), mid, j, count;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2, count = 0, j = matrix[0].size() - 1;
            for (int i = 0; i < matrix.size(); i++) {
                while (j >= 0 && matrix[i][j] > mid) j--;
                count += (j + 1);
            }
            if (count < k) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};

// Use a heap.similar to p0373. Time complexity is O(k*log(n)). But slow.
class Solution2 {
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