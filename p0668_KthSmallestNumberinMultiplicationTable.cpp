#include <vector>

using namespace std;

// Use binary search. Every step we can count how many numbers less than mid by sum of min(mid / i, n) and
// compare count with k. Time complexity O(m*log(m*n)).
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lo = 1, hi = m * n, mid, count;
        while (lo < hi) {
            mid = (lo + hi) / 2, count = 0;
            for (int i = 1; i <= m; i++) count += min(mid / i, n);
            if (count < k) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};