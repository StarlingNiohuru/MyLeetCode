#include <vector>

using namespace std;

// similar to p0300.Time complexity is O(n).
class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        int t1 = INT32_MAX, t2 = INT32_MAX;
        for (int num:nums) {
            if (num <= t1) t1 = num;
            else if (num <= t2) t2 = num;
            else return true;
        }
        return false;
    }
};
