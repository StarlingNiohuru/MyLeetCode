#include <vector>
#include <queue>

using namespace std;

// Use a heap
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        vector<vector<int>> res;
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> pq;
        for (vector<int> x:points) pq.push({x[0] * x[0] + x[1] * x[1], x});
        for (int i = K; i > 0; i--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};