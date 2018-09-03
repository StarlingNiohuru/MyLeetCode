#include <iostream>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int b;
        b = (n ^ (n >> 1));
        return (b & (b + 1)) == 0;
    }
};

