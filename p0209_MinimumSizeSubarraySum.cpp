#include <vector>

using namespace std;

// Use sliding window with 2 pointers. similar to p0076
class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int i = 0, j = 0, sum = 0, res = INT32_MAX;
        while (j < nums.size()) {
            sum += nums[j];
            while (sum >= s) {
                res = min(res, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return (res == INT32_MAX) ? 0 : res;
    }
};