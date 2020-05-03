#include <vector>
#include <algorithm>

using namespace std;

// Sort the list and traverse it from large until citations[n - 1 - h] <= h.
// Time complexity is O(log(n)) and space complexity is O(1).
class Solution {
public:
    int hIndex(vector<int> &citations) {
        sort(citations.begin(), citations.end());
        int i = 0, n = citations.size();
        while (i < n && citations[n - 1 - i] > i) i++;
        return i;
    }
};