#include <vector>

using namespace std;

// This problem can be transferred to a matrix problem by M[i][j] = A[i]/A[n - 1 - j]. Then solve it like p0378.
// Notice that we need to record the max number's index of every row when calculating the count so at last we can get
// the greatest number which less than mid. When count = K , the max number's corresponding p and q are the answers.
// Time complexity is O(n*log(n)).
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &A, int K) {
        vector<int> res = {0, 1};
        double lo = 0, hi = 1, mid;
        int n = A.size(), j, count;
        while (hi - lo > 1e-9) {
            mid = lo + (hi - lo) / 2.0, count = 0, j = n - 1, res[0] = 0, res[1] = 1;
            for (int i = 0; i < n; i++) {
                while (j >= 0 && A[i] > A[n - 1 - j] * mid) j--;
                count += (j + 1);
                if (j >= 0 && res[0] * A[n - 1 - j] < A[i] * res[1])
                    res[0] = A[i], res[1] = A[n - 1 - j];
            }
            if (count == K) break;
            else if (count < K) lo = mid;
            else hi = mid;
        }
        return res;
    }
};