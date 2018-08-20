#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        return (b != 0) ? getSum(a ^ b, (a & b) << 1) : a;
    }
};
