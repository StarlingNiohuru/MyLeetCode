using namespace std;

bool isBadVersion(int version);

// Binary search. notice that we use mid = low + (high - low)/2 to avoid overflow. Time complexity is O(log(n)).
class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n, mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2; // avoid int overflow
            if (isBadVersion(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};