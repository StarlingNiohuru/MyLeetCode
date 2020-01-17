#include <vector>

using namespace std;

// iteration without dp. Time complexity is O(n). similar to p0509.
class Solution {
public:
    int tribonacci(int n) {
        int t1 = 0, t2 = 1, t3 = 1, res = (n > 0) ? 1 : 0;
        for (int i = 3; i <= n; i++) {
            res = t1 + t2 + t3;
            t1 = t2;
            t2 = t3;
            t3 = res;
        }
        return res;
    }
};
