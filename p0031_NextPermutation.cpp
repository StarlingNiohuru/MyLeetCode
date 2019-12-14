#include <vector>
#include <utility>

using namespace std;

// First we need to search the first nums[j] > nums[i] (i = j + 1) from backend to start. Then search k from i to end
// where nums[k] > nums[j] and nums[k+1] <= nums[j]. Swap nums[j] and nums[k]. At last reverse the sublist nums[i:].
class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int i = nums.size() - 1, j;
        while (i > 0 && nums[i] <= nums[i - 1]) i--;
        j = i - 1;
        if (j >= 0) {
            while (i < nums.size() - 1 && nums[i + 1] > nums[j]) i++;
            swap(nums[i], nums[j]);
        }
        i = j + 1, j = nums.size() - 1;
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};