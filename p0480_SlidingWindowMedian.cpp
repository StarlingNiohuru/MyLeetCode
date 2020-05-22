#include <set>

using namespace std;

// similar to p0295. But only use 1 pointer(mid) instead. Time complexity is O(n*log(n)). Space complexity is O(n).
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        vector<double> res;
        multiset<int> s(nums.begin(), nums.begin() + k);
        auto mid = next(s.begin(), k / 2); // mid is the high median at first, but has a flexible usage behind.
        for (int i = 0; i + k <= nums.size(); i++) {
            res.push_back(((double) (*mid) + *next(mid, k % 2 - 1)) * 0.5);
            if (i + k == nums.size()) break;
            s.insert(nums[i + k]);
            if (nums[i + k] < *mid) mid--;
            if (nums[i] <= *mid) mid++;
            s.erase(s.lower_bound(nums[i]));
        }
        return res;
    }
};