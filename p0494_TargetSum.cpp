#include <vector>

using namespace std;

// backtracking. method of exhaustion.
// Time complexity is O(2^n) and space complexity is O(n) where n is the length of nums.
class Solution {
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