#include <vector>
#include <algorithm>
#include <list>

using namespace std;

// greedy. We sort people[] by: If a.h>b.h or if a.h==b.h and a.k<b.k, put a before b. Then for each p in people[],
// insert p at the p.k index of the new list people[] because everyone before p.k has a greater height than p. Repeat.
// Use a linked-list instead of a vector to improve performance. Time complexity is O(n^2) and Space complexity is O(n).
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(),
             [](vector<int> a, vector<int> b) { return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]); });
        list<vector<int>> l;
        for (auto &p : people) {
            auto pos = l.begin();
            advance(pos, p[1]);
            l.insert(pos, p);
        }
        return vector<vector<int>>(l.begin(), l.end());
    }
};