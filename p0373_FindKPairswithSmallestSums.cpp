#include <vector>
#include <utility>
#include <queue>

using namespace std;

// Because all the inner lists are sorted, we can compare the nums of the first column (like(0,0),(1,0),(2,0)...).
// Then the problem now is similar to p0023. We use a heap to find the smallest (nums1[i]+nums2[j]) and fill the gap
// with (i,j+1). Time complexity is O(k*log(k)).
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<vector<int>> res;
        if (nums1.empty() || nums2.empty()) return res;
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> pq;
        for (int i = 0; i < nums1.size() && i < k; i++) pq.push({nums1[i] + nums2[0], {i, 0}});
        while (k > 0 && !pq.empty()) {
            auto tmp = pq.top();
            int x = tmp.second[0], y = tmp.second[1];
            res.push_back({nums1[x], nums2[y]});
            pq.pop();
            k--;
            if (y < nums2.size() - 1) pq.push({nums1[x] + nums2[y + 1], {x, y + 1}});
        }
        return res;
    }
};