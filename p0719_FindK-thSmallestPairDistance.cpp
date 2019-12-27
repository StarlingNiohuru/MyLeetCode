#include <vector>
#include <algorithm>

using namespace std;

// This problem can be transferred to a matrix problem like p0378. We sort the nums and arrange the list as a matrix
// like A[i][j] = nums[i] - nums[n - 1 - j]. Then solve it by binary search as p0378. Time complexity is O(n*log(n)).
class Solution {
public:
    int smallestDistancePair(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), lo = 0, hi = nums.back() - nums.front(), mid, j, count;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2, count = 0, j = nums.size() - 1;
            for (int i = 0; i < n; i++) {
                while (j >= 0 && (nums[i] - nums[n - 1 - j]) > mid) j--;
                count += (j + 1);
            }
            if (count < k + n * (n + 1) / 2) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};