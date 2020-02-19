#include <vector>

using namespace std;

// dp iteration. dp[i][j+1000] represents how many ways nums[0,i] can have a sum of j.(We let j+1000 because sum will
// not exceed 1000.) We have: dp[i][j] = dp[i - 1][j - nums[i]] + dp[i - 1][j + nums[i]]. dp[n-1][S+1000] is the answer.
// Time complexity is O(n) and space complexity is O(n).
class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int S) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2001, 0));
        dp[0][nums[0] + 1000] = 1;
        dp[0][-nums[0] + 1000] += 1; // if nums[0]=0, dp[0][0+1000] will be 2. so we need dp++.
        for (int i = 1; i < n; i++)
            for (int sum = -1000; sum <= 1000; sum++) {
                if (dp[i - 1][sum + 1000] > 0) {
                    dp[i][sum + nums[i] + 1000] += dp[i - 1][sum + 1000];
                    dp[i][sum - nums[i] + 1000] += dp[i - 1][sum + 1000];
                }
            }
        return S > 1000 ? 0 : dp[n - 1][S + 1000];
    }
};

// backtracking. method of exhaustion.
// Time complexity is O(2^n) and space complexity is O(n) where n is the length of nums.
class Solution2 {
private:
    void backtrack(vector<int> &nums, int &count, int &S, int sum, int i) {
        if (i == nums.size()) {
            if (sum == S) count++;
        } else {
            backtrack(nums, count, S, sum + nums[i], i + 1);
            backtrack(nums, count, S, sum - nums[i], i + 1);
        }
    }

public:
    int findTargetSumWays(vector<int> &nums, int S) {
        int res = 0;
        backtrack(nums, res, S, 0, 0);
        return res;
    }
};