#include <vector>
#include <map>

using namespace std;

// Brute force method will cause Time Limit Exceeded. So use a tree map sorting by left value with recording the index.
// Time complexity is O(n*log(n)).
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals) {
        vector<int> res;
        map<int, int> intervalLeftIndex;
        for (int i = 0; i < intervals.size(); i++)
            intervalLeftIndex[intervals[i].front()] = i;
        for (auto &interval : intervals) {
            auto it = intervalLeftIndex.lower_bound(interval[1]);
            if (it == intervalLeftIndex.end()) res.push_back(-1);
            else res.push_back(it->second);
        }
        return res;
    }
};