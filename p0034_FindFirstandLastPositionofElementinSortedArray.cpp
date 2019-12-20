#include <vector>

using namespace std;

// Use binary search to look for left boundary first.Then search the right boundary.Time complexity is O(log(n)).
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> res = {-1, -1};
        if (nums.empty()) return res;
        int lo = 0, hi = nums.size() - 1, mid;
        while (lo < hi) { // eliminate lo = hi to avoid infinite loop
            mid = (lo + hi) / 2;
            if (nums[mid] == target) hi = mid;
            else if (nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        if (nums[lo] == target) res[0] = lo;
        else return res;
        lo = 0, hi = nums.size() - 1;
        while (lo < hi) { // same as line 12
            mid = (lo + hi + 1) / 2; // avoid case like [7,8] (target =7) causing infinite loop
            if (nums[mid] == target) lo = mid;
            else if (nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        res[1] = lo;
        return res;
    }
};