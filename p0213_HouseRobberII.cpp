class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> nums1(nums.begin(), nums.end() - 1), num2(nums.begin() + 1, nums.end());
        return max(robOriginal(nums1), robOriginal(num2));
    }

private:
    int robOriginal(vector<int> &nums) {
        if (nums.empty()) return 0;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        if (nums.size() > 1) dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        return dp[nums.size() - 1];
    }
};