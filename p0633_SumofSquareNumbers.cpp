using namespace std;

// We can traverse a from [0,sqrt(c)] and use function isPerfectSquare() (see p0367) to check c-a*a whether is a
// perfect square number. Time complexity is O(sqrt(c)*log(c)), which is not the best one.
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long i = 0; i * i <= c; i++)
            if (isPerfectSquare(c - i * i)) return true;
        return false;
    }

private:
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
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