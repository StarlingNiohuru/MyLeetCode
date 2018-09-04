#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int i, j, bitCount, res;
        unordered_set<int> prime = {2, 3, 5, 7, 11, 13, 17, 19};
        res = 0;
        for (i = L; i < R + 1; i++) {
            bitCount = 0;
            j = i;
            while (j) {
                j &= (j - 1);
                bitCount++;
            }
            res += prime.count(bitCount);
        }
        return res;
    }
};

