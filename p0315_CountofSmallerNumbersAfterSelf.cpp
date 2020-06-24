#include <vector>

using namespace std;

// Traverse the nums[] from right to left and keep a sorted list temp[]. On each step we calculate the index(idx) of nums[i]
// in temp[] and idx is res[i]. Then we insert nums[i] to temp[] and continue. We can implement it by multiset(BST) and
// distance() but we will get a TLE because complexity is O(n^2). So we have to use a sorted vector instead.
// Time complexity is still O(n^2) and Space complexity is O(n).
class Solution {
private:
    // lo is just >= target
    int binarySearch(vector<int> &sortedNums, int target) {
        int lo = 0, hi = sortedNums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (sortedNums[mid] < target) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }

public:
    vector<int> countSmaller(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n), temp;
        for (int i = n - 1; i >= 0; i--) {
            res[i] = binarySearch(temp, nums[i]);
            temp.insert(temp.begin() + res[i], nums[i]);
        }
        return res;
    }
};