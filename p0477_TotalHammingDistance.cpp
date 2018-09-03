#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int> &nums) {
        int i, j, bitCount, res;
        res = 0;
        for (i = 0; i < 32; i++) {
            bitCount = 0;
            for (j = 0; j < nums.size(); j++) {
                bitCount += (nums[j] >> i) & 1;
            }
            res += bitCount * (nums.size() - bitCount);
        }
        return res;
    };
};
