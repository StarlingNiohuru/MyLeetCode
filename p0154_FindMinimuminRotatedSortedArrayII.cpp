#include <vector>

using namespace std;

// Only one more line than p0153, when nums[mid] = nums[right], let right - 1. Average time complexity can be O(log(n)).
// But at the worst case like [1,1,1,1,1], it's O(n).
class Solution {
public:
    int findMin(vector<int> &nums) {
        int lo = 0, hi = nums.size() - 1, mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (nums[mid] > nums[hi]) lo = mid + 1;
            else if (nums[mid] == nums[hi]) hi--;
            else hi = mid;
        }
        return nums[lo];
    }
};

// same as p0081.
class Solution2 {
public:
    int findMin(vector<int> &nums) {
        for (int num:nums) if (num < nums[0]) return num;
        return nums[0];
    }
};