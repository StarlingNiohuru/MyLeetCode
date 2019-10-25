#include <vector>
#include <unordered_map>
#include <utility>
#include <queue>

using namespace std;

// Use a hashmap to count frequency then use a heap to find top k
class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> res;
        unordered_map<int, int> frequentMap;
        for (int x:nums) frequentMap[x]++;
        priority_queue<pair<int, int>> pq;
        for (pair<int, int> x:frequentMap)
            pq.push({x.second, x.first});
        for (int i = k; i > 0; i--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};