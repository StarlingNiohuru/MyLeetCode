#include <vector>

using namespace std;
// Greedy. Traverse A from left. If we meet a 0,flip all in [i,i+k]. But we'll get TLE if implementing it by a simple way.
// Instead we use a variable 'flips' to record how many times in [i-K+1,i-1] are flipped. If flips % 2 == A[i], that means
// we need to flip A[i,i+K] (actually not). We can use a queue or simply let A[i]+2 to mark it. Then traverse A and count
// the result just one time.Time complexity is O(n), space complexity is O(1).

class Solution {
public:
    int minKBitFlips(vector<int> &A, int K) {
        int n = A.size(), res = 0, flips = 0;
        for (int i = 0; i < n; i++) {
            if (i >= K && A[i - K] > 1) {
                flips--;
                A[i - K] -= 2;
            }
            if (flips % 2 == A[i]) {
                if (i + K > n) return -1;
                A[i] += 2;
                flips++;
                res++;
            }
        }
        return res;
    }
};