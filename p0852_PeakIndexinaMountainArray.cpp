#include <vector>

using namespace std;

// Binary search. Time complexity is O(log(n)). Space complexity is O(1).
class Solution {
public:
    int peakIndexInMountainArray(vector<int> &A) {
        int lo = 0, hi = A.size() - 1;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (A[mi] < A[mi + 1]) lo = mi + 1;
            else hi = mi;
        }
        return lo;
    }
};