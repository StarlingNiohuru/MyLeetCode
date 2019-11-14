#include <vector>

using namespace std;

// Solve this problem by XOR (^) operator. XOR has some characters: a^b = b^a. (a^b)^c = a^(b^c).a^a=0. a^0=a.
// So a^b^c^a^c^x... = (a^a^b^b^c^c...)^x = x.
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int res = 0;
        for (int num:nums)
            res ^= num;
        return res;
    }
};