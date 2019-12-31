#include <vector>

using namespace std;

// Greedy. First we denote 0 + nums[0] as farthest1. Then we traverse between [0,farthest1] and record the max
// j+nums[j] as farthest2. Then we traverse [farthest1+1, farthest2] to find the max k+nums[k] and so on.The answer is
// the count of steps. We can prove this method which can find the shortest route with proof by contradiction.
// Time complexity is O(n).
class Solution {
public:
    int jump(vector<int> &nums) {
        int farthest1 = 0, farthest2 = 0, res = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest2 = max(farthest2, i + nums[i]);
            if (i == farthest1) {
                farthest1 = farthest2;
                res++;
            }
        }
        return res;
    }
};