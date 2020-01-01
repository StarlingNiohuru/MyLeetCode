using namespace std;

// Use binary search. Because sqrt(x) is always >= 0 and when x>=4 sqrt(x)>=x/2, we set lo=0 and hi=x/2 +1.
// Time complexity is O(log(n)).
class Solution {
public:
    int mySqrt(int x) {
        long lo = 0, hi = x / 2 + 1, mid;
        while (lo < hi) { // eliminate lo = hi to avoid infinite loop
            mid = lo + (hi - lo + 1) / 2; // avoid infinite loop
            if (mid * mid > x) hi = mid - 1;
            else lo = mid;
        }
        return lo;
    }
};