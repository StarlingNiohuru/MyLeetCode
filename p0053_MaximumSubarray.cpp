#include <climits>

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
//        add every element from left to right. If sum is negative, reset sum to 0. Find the max sum
        int res = INT_MIN, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            res = max(res, sum);
            sum = max(sum, 0);
        }
        return res;
    }
};