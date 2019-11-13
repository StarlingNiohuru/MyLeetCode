using namespace std;

// One example: n = 100a + 10b + c = 99a + 9b + (a + b + c) = 9(11a + b) + m, (m = a + b + c)
// Then m = 10d + e = 9d+ (d + e). n = 9(11a + b + d ) + (d + e).
// We can continue the process above until last term is less than 10. At last n % 9 is what we want (n % 9 ! = 0).
// But notice when n % 9 = 0 the answer is 9. So we change n & 9 to (n - 1) % 9 + 1.
class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};