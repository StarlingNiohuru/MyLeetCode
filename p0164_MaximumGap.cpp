#include <vector>

using namespace std;

// bucket sort. Every loop, group the nums by digit of every bit. Then use count[] to record the number of each group.
// Let count[i] += count[i - 1] and count[j] - 1 can represent the max index of group j in new nums (temp[]). Reorder
// the list and repeat. Time complexity is O(n). Space complexity is O(n).
class Solution {
public:
    int maximumGap(vector<int> &nums) {
        if (nums.empty() || nums.size() < 2) return 0;
        int exp = 1, maxVal = INT32_MIN, res = 0;
        for (int num:nums) maxVal = max(maxVal, num);
        vector<int> temp(nums.size());
        while (maxVal / exp > 0) {
            vector<int> count(10, 0);
            for (int num:nums) count[(num / exp) % 10]++;
            for (int i = 1; i < count.size(); i++) count[i] += count[i - 1];
            for (int i = nums.size() - 1; i >= 0; i--)
                temp[--count[(nums[i] / exp) % 10]] = nums[i];
            for (int i = 0; i < nums.size(); i++) nums[i] = temp[i];
            exp *= 10;
        }
        for (int i = 1; i < nums.size(); i++) res = max(res, nums[i] - nums[i - 1]);
        return res;
    }
};