#include <vector>
#include <utility>

using namespace std;

// similar to p0448
class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 1;
        for (int i = 0; i < n; i++)
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1) return i + 1;
        return n + 1;
    }
};