#include <iostream>
#include <cstdint>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i, digit;
        uint32_t res = 0;
        for (i = 0; i < 32; i++) {
            digit = n & 1;
            res = (res << 1) + digit;
            n >>= 1;
        }
        return res;
    }
};
