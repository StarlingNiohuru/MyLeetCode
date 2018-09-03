#include <iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res, diff;
        res = 0;
        diff = x ^ y;
        while (diff) {
            diff &= (diff - 1);
            res++;
        }
        return res;
    }
};

