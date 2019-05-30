#include <climits>

class Solution {
public:
    int maximumProduct(vector<int> &nums) {
//        Find 2 smallest and 3 largest elements
        if (nums.size() < 3) return 0;
        int min1 = INT_MAX, min2 = INT_MAX, max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < min2) {
                if (nums[i] < min1) min2 = min1, min1 = nums[i];
                else min2 = nums[i];
            }
            if (nums[i] > max1) {
                if (nums[i] > max2) {
                    if (nums[i] > max3) max1 = max2, max2 = max3, max3 = nums[i];
                    else max1 = max2, max2 = nums[i];
                } else max1 = nums[i];
            }
        }
        return max(min1 * min2 * max3, max1 * max2 * max3);
    }
};