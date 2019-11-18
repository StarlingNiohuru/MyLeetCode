#include <vector>

using namespace std;

// Divide the nums into 2 groups by a mask which can distinguish the 2 single numbers (a and b).XOR all the nums
// and we can get m = a XOR b. Then pick the last different binary bit between a and b (also the last bit 1 of m)
// as the mask = m & ~(m - 1). Use the mask to separate nums and find the single number each (same as p0136)
class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        int mask = 0;
        vector<int> res = {0, 0};
        for (int num:nums)
            mask ^= num;
        mask = mask & ~(mask - 1);
        for (int num:nums) {
            if ((num & mask) == 0) res[0] ^= num;
            else res[1] ^= num;
        }
        return res;
    }
};