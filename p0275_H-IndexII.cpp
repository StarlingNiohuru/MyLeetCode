#include <vector>

using namespace std;

// similar to p0274. Time complexity is O(n) and space complexity is O(1).
class Solution {
public:
    int hIndex(vector<int> &citations) {
        int i = 0, n = citations.size();
        while (i < n && citations[n - 1 - i] > i) i++;
        return i;
    }
};