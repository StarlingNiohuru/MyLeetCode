#include <vector>

using namespace std;

// According to description, nums[-1] = nums[n] = -∞. It means if nums[i] < nums[i + 1], there must be a peak in [i+1,n-1].
// So we can use binary search to find it. Time complexity is O(log(n)). Space complexity is O(1).
class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (nums[mi] < nums[mi + 1]) lo = mi + 1;
            else hi = mi;
        }
        return lo;
    }
};