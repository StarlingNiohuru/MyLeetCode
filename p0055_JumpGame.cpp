#include <vector>

using namespace std;

// Traverse from right to left. If i + nums[i]>= nums[n-1], that means position i is reachable.Then we make i
// last reachable position and search next i which satisfies i + nums[i] >= lastReachable. And so on until i=0.
// Time complexity is O(n).
class Solution {
public:
    bool canJump(vector<int> &nums) {
        int lastReachableIndex = nums.size() - 1;
        for (int i = lastReachableIndex; i >= 0; i--) {
            if (i + nums[i] >= lastReachableIndex) lastReachableIndex = i;
        }
        return lastReachableIndex == 0;
    }
};