#include <vector>

using namespace std;

// dp iteration. First we cut nums into n/k parts (n is the length of nums). leftMax[i] represents the max of
// nums[left,i] (left means the left num of a part). rightMax[i] is in the same way. Then the answer of every window is
// max(rightMax[i], leftMax[i + k - 1]). Time complexity is O(n).
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        if (k == 0) return {};
        int n = nums.size();
        vector<int> leftMax(n), rightMax(n), res;
        for (int i = 0; i < n; i++) {
            if (i % k == 0) leftMax[i] = nums[i];
            else leftMax[i] = max(leftMax[i - 1], nums[i]);
            int j = n - 1 - i;
            if ((j + 1) % k == 0 || j == n - 1) rightMax[j] = nums[j];
            else rightMax[j] = max(rightMax[j + 1], nums[j]);
        }
        for (int i = 0; i <= n - k; i++)
            res.push_back(max(rightMax[i], leftMax[i + k - 1]));
        return res;
    }
};