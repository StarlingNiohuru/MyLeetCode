#include <vector>

using namespace std;

// The main difference between this problem and p0033 is searching the pivot index. The list can be
// [1,3,1,1,1] or [1,1,1,3,1] or [1,1,1,1,1] etc. so we can't solve it by binary search in O(log(n)).
// Hence we use linear search instead at the first step. Time complexity is O(n).
class Solution {
public:
    bool search(vector<int> &nums, int target) {
        int n = nums.size(), lo = 0, hi = n - 1, mid, pivot;
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || nums[i] > nums[i + 1]) {
                pivot = i + 1;
                break;
            }
        }
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (nums[(mid + pivot) % n] == target) return true;
            else if (nums[(mid + pivot) % n] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return false;
    }
};