#include <cstdlib>

using namespace std;

// We need to find n ( n * divisor <= dividend, (n + 1) * divisor > dividend) instead. A quicker method is to let
// divisor = divisor * 2 every step (1,2,4,8...times divisors). When k*divisors > dividend, let
// dividend = dividend - k*divisors. Then repeat the process until the final dividend < divisor.
// Be cautious of int 32 limits [-2147483648, 2147483647]
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool positive = (dividend ^ divisor) >= 0;
        long dividendLong = dividend, divisorLong = divisor;
        dividendLong = labs(dividendLong), divisorLong = labs(divisorLong);
        long resLong = 0, tempDividend = dividendLong;
        while (tempDividend >= divisorLong) {
            long quotient = 1, tempDivisor = divisorLong;
            while (tempDivisor + tempDivisor <= tempDividend) {
                tempDivisor += tempDivisor;
                quotient += quotient;
            }
            tempDividend = tempDividend - tempDivisor;
            resLong += quotient;
        }
        int res;
        if (positive) res = (resLong <= INT32_MAX) ? (int) resLong : INT32_MAX;
        else res = (-resLong >= INT32_MIN) ? (int) -resLong : INT32_MIN;
        return res;
    }
};