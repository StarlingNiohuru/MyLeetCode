#include <cmath>

using namespace std;

// This problem is identical to searching how many k (1<=k<=n) which have odd factors. We can find only perfect square
// (like m^2) have odd factors. Because a non perfect square must has j pairs of different factors which are even. In
// contrast perfect square numbers have odd ones. So simply sqrt(n) is the answer. Time and Space complexity are O(1).
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};