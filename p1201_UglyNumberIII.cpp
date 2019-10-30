#include <algorithm>

using namespace std;

// Notice: The definition of ugly number of this problem is quite different from ugly number problems.
// We can select all the multiples of a,b,c: F(N) = a + b + c - a ∩ c - a ∩ b - b ∩ c + a ∩ b ∩ c
// F(N) = N/a + N/b + N/c - N/lcm(a, c) - N/lcm(a, b) - N/lcm(b, c) + N/lcm(a, b, c) (lcm = least common multiple)
// Use binary search to find the least N when F(N) = n (There are many Ns satisfying f(N) = n)
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long left = 1, right = 2 * 1e9, mid, tmp;
        long la = long(a), lb = long(b), lc = long(c);
        long ab = la * lb / __gcd(la, lb), bc = lb * lc / __gcd(lb, lc), ac = la * lc / __gcd(la, lc),
                abc = ab * lc / __gcd(ab, lc);
        while (left < right) {
            mid = (left + right) / 2;
            tmp = mid / la + mid / lb + mid / lc - mid / ab - mid / bc - mid / ac + mid / abc;
            if (tmp < n) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};