#include <vector>
#include <algorithm>

using namespace std;

// Use 2 pointers in a sorted list to find a pair(a,b) satisfying b+c=-a.
// Time complexity is O(n2), space complexity is O(1).
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        if (nums.empty()) { return {}; }
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] < 0 || (l > i + 1 && nums[l] == nums[l - 1])) l++;
                else if (nums[i] + nums[l] + nums[r] > 0 || (r < nums.size() - 1 && nums[r] == nums[r + 1])) r--;
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
            }
        }
        return res;
    }
};
