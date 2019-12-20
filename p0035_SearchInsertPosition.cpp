#include <vector>

using namespace std;

// Binary search. Time complexity is O(log(n)).
class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int lo = 0, hi = nums.size() - 1, mid;
        while (lo <= hi) { // Enable lo=hi. when target= 7, [..5,6..] will stop at idx[6]+ 1; [..8,9..] will stop at idx[8]- 1.
            mid = (lo + hi) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return lo;
    }
};