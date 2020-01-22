#include <vector>
#include <algorithm>

using namespace std;

// greedy.Sort the list by pair[1] then traverse and count valid pairs.Time complexity is O(n*log(n)).
// But don't know why so slow.
class Solution {
public:
    int findLongestChain(vector<vector<int>> &pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b) {
            return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]);
        });
        int res = 0, temp = INT32_MIN;
        for (int i = 0; i < pairs.size(); i++) {
            if (i == 0 || temp < pairs[i][0]) {
                temp = pairs[i][1];
                res++;
            }
        }
        return res;
    }
};