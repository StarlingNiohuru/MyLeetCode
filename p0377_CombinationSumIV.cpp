#include <vector>

using namespace std;

// Backtracking recursion method induces Time Limit Exceeded problem. Dynamic Programming iteration is the best way.
// Given a candidate nums [x1,x2...xn], dp[k] represents the number of combinations when target = k. There is:
// dp[k] = dp[k-x1] + dp[k-x2]...+ dp[k-xn] (k>=x1, k>=x2, ..., k>=xn)
class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
            for (int j:nums) {
                if (i >= j) {
                    if (dp[i] >= INT32_MAX - dp[i - j]) dp[i] = 0;
                    else dp[i] += dp[i - j];
                }
            }
        return dp[target];
    }
};