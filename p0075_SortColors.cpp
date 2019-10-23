#include <utility>

using namespace std;

// Use 3 pointers. p0 is used to track the left boundary of 0s. p2 is used to track the right boundary of 2s.
// p is used to track 1s. This is also called "Dutch national flag problem".
class Solution {
public:
    void sortColors(vector<int> &nums) {
        int pointer = 0, pointer0 = 0, pointer2 = nums.size() - 1;
        while (pointer <= pointer2) {
            if (nums[pointer] == 0) {
                swap(nums[pointer++], nums[pointer0++]);
            } else if (nums[pointer] == 2) {
                swap(nums[pointer], nums[pointer2--]);
            } else pointer++;
        }
    }
};