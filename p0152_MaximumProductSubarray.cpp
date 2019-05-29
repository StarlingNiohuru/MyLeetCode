#include <climits>

class Solution {
public:
    int maxProduct(vector<int> &nums) {
//        Multiply every element from left to right and right to left at the same time. If product(left or right) is 0, reset it to 1. Find the max
        int n = nums.size(), leftProduct = 1, rightProduct = 1, res = INT_MIN;
        if (n == 0) res = 0;
        for (int i = 0; i < n; i++) {
            leftProduct *= nums[i];
            rightProduct *= nums[n - i - 1];
            res = max(res, max(leftProduct, rightProduct));
            leftProduct = (leftProduct == 0) ? 1 : leftProduct;
            rightProduct = (rightProduct == 0) ? 1 : rightProduct;
        }
        return res;
    }
};