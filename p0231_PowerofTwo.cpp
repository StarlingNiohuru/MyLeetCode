#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) { return false; }
        int i, count;
        count = 0;
        for (i = 0; i < 32; i++) {
            count += (n & 1);
            if (count > 1) { return false; }
            n >>= 1;
        }
        return true;
    }
};
