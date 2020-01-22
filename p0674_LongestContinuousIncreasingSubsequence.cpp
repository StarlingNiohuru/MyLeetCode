#include <vector>

using namespace std;

// Traverse and count continuous sequences.Time complexity is O(n).
class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        int res = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] > nums[i - 1]) count++;
            else count = 1;
            res = max(res, count);
        }
        return res;
    }
};