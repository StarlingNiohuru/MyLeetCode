#include <iostream>
#include <cstdint>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int i, res;
        res = 0;
        for (i = 0; i < 32; i++) {
            res += (n & 1);
            n >>= 1;
        }
        return res;
    }
};
