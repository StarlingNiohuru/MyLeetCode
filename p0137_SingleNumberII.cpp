#include <vector>

using namespace std;

// Use a array countOfOnes[32] to record the count of '1's in every bit. For every bit if count % 3 = 1,
// it shows that the bit digit of the single num in the list is 1. Vice versa of 0.
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int res = 0;
        int countOfOnes[32] = {0};
        for (int num:nums) {
            for (int i = 31; i >= 0; i--) {
                if ((num & 1) == 1) countOfOnes[i]++;
                num >>= 1;
            }
        }
        for (int count:countOfOnes) {
            res <<= 1;
            if (count % 3 == 1) res |= 1;
        }
        return res;
    }
};