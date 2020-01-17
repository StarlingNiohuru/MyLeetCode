#include <vector>

using namespace std;

// iteration without dp. (It acts like dp[i] = dp[i - 1] + dp[i - 2]). Time complexity is O(n).
class Solution {
public:
    int fib(int N) {
        int f1 = 0, f2 = 1, res = (N > 0) ? 1 : 0;
        for (int i = 2; i <= N; i++) {
            res = f1 + f2;
            f1 = f2;
            f2 = res;
        }
        return res;
    }
};