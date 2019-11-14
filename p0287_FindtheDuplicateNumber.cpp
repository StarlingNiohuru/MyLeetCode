#include <vector>

using namespace std;

// This problem can be changed to cycle point searching problem. According to given condition, we can let points move
// by point = num[point] just like point = point->next of a linked list. Then the problem is almost the same as p0142.
class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int slow = 0, fast = 0, slow2 = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (fast != slow);
        while (slow != slow2) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow;
    }
};