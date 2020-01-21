#include <vector>
#include <algorithm>

using namespace std;

// Sort the 2-D vector by envelope[0] first. But notice: for example when we meet [1,3] and [1,5], we need put [1,5]
// before [1,3] because according to problem's description we can't envelop [1,3] into [1,5]. After sorting, we will
// found this problem has been transferred into p0300. Time complexity is O(n*log(n)). Space complexity is O(n).
class Solution {
public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        if (envelopes.empty() || envelopes[0].empty()) return 0;
        sort(envelopes.begin(), envelopes.end(), [](vector<int> a, vector<int> b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        vector<int> tail;
        for (auto envelope:envelopes) {
            if (tail.empty() || envelope[1] > tail.back()) tail.push_back(envelope[1]);
            else {
                auto it = lower_bound(tail.begin(), tail.end(), envelope[1]);
                *it = envelope[1];
            }
        }
        return tail.size();
    }
};