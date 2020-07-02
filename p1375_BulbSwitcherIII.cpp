#include <vector>

using namespace std;

// We can find when all the bulbs are blue, the number of lighted bulbs is equal to the rightmost lighted bulb. So we use
// a rightLighted for recording the index of the rightmost lighted bulb. Then traverse the light[] and count the result.
// Time complexity is O(n). space complexity is O(1).
class Solution {
public:
    int numTimesAllBlue(vector<int> &light) {
        int rightLighted = 0, res = 0;
        for (int i = 0; i < light.size(); i++) {
            rightLighted = max(rightLighted, light[i]);
            if (rightLighted == i + 1) res++;
        }
        return res;
    }
};