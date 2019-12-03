#include <vector>
#include <unordered_map>
#include <utility>
#include <queue>

using namespace std;

// Use a hashmap to count frequency then use a heap to find top k. Time complexity is O(n*log(k))
class Solution {
private:
    struct compare {
        bool operator()(const pair<int, string> &a, const pair<int, string> &b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        }
    };

public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        vector<string> res;
        unordered_map<string, int> frequentMap;
        for (string word:words) frequentMap[word]++;
        priority_queue<pair<int, string>, vector<pair<int, string>>, compare> pq;
        for (pair<string, int> x:frequentMap)
            pq.push({x.second, x.first});
        for (int i = k; i > 0; i--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};