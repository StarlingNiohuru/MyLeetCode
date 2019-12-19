#include <vector>

using namespace std;

// same as p0081.
class Solution {
public:
    int findMin(vector<int> &nums) {
        for (int num:nums) if (num < nums[0]) return num;
        return nums[0];
    }
};