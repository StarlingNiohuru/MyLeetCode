using namespace std;

// Binary search. similar to p0069. Time complexity is O(log(n)).
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 0) return false;
        long lo = 0, hi = num / 2 + 1, mid;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (mid * mid == num) return true;
            if (mid * mid > num) hi = mid - 1;
            else lo = mid + 1;
        }
        return false;
    }
};