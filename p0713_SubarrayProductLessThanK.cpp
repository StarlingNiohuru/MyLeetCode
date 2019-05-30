class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int product = 1, res = 0;
        for (int left = 0, right = 0; right < nums.size(); right++) {
            product *= nums[right];
            while (left <= right && product >= k) product /= nums[left++];
            res += right - left + 1;
        }
        return res;
    }
};