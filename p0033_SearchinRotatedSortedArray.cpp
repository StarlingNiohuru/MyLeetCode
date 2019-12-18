#include <vector>

using namespace std;

// First use binary search to find the min number's index (pivot). Then search the target by binary search.
// Time complexity is O(log(n)).
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size(), lo = 0, hi = n - 1, mid, pivot;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (nums[mid] > nums[hi]) lo = mid + 1;
            else hi = mid;
        }
        pivot = lo, lo = 0, hi = n - 1;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (nums[(mid + pivot) % n] == target) return (mid + pivot) % n;
            else if (nums[(mid + pivot) % n] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }
};