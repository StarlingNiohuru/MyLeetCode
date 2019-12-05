#include <unordered_map>
#include <utility>
#include <queue>

using namespace std;

// similar to p0347
class Solution {
public:
    string frequencySort(string s) {
        string res;
        unordered_map<char, int> frequentMap;
        for (char x:s) frequentMap[x]++;
        priority_queue<pair<int, char>> pq;
        for (pair<char, int> x:frequentMap)
            pq.push({x.second, x.first});
        while (!pq.empty()) {
            for (int i = pq.top().first; i > 0; i--)
                res += pq.top().second;
            pq.pop();
        }
        return res;
    }
};