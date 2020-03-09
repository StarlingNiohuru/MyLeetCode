#include <vector>

using namespace std;

// dp iteration. leftSub[i] represents the first index of the left sub array which has the max left sum when the middle
// sub arrays is [i,i+k]. So does rightSub[i]. Then we can calculate every leftSub[i] and rightSub[i]. At last we can
// find the max sum of (leftSub[i], midSub[i], rightSub[i]) and record the answer.
// Time complexity is O(n) and space complexity is O(n).
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
        int n = nums.size(), maxSub, maxSum = 0;
        vector<int> sum(n + 1, 0), res;
        vector<int> leftSub(n, 0), rightSub(n, 0);
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + nums[i];
        maxSub = 0;
        for (int i = k; i <= n - 2 * k; i++) {
            if (sum[i] - sum[i - k] > maxSub) {
                leftSub[i] = i - k;
                maxSub = sum[i] - sum[i - k];
            } else leftSub[i] = leftSub[i - 1];
        }
        maxSub = 0;
        for (int i = n - 2 * k; i >= k; i--) {
            if (sum[i + 2 * k] - sum[i + k] >= maxSub) {
                rightSub[i] = i + k;
                maxSub = sum[i + 2 * k] - sum[i + k];
            } else rightSub[i] = rightSub[i + 1];
        }
        for (int i = k; i <= n - 2 * k; i++) {
            int l = leftSub[i], r = rightSub[i];
            int tot = (sum[i + k] - sum[i]) + (sum[l + k] - sum[l]) + (sum[r + k] - sum[r]);
            if (tot > maxSum) {
                maxSum = tot;
                res = {l, i, r};
            }
        }
        return res;
    }
};