#include <vector>
#include <unordered_set>

using namespace std;

// similar to p0306. We use a set to check whether a new sum is in list A. Time complexity is O(n^2*log(m)) where m is
// the max of the list A.
class Solution {
public:
    int lenLongestFibSubseq(vector<int> &A) {
        unordered_set<int> aSet(A.begin(), A.end());
        int n = A.size(), res = 0;
        for (int i = 0; i < n - 2; i++)
            for (int j = i + 1; j < n - 1; j++) {
                int count = 2;
                long d1 = A[i], d2 = A[j], d3 = d1 + d2;
                while (aSet.count(d3) && d3 <= 1000000000) {
                    count++;
                    d1 = d2;
                    d2 = d3;
                    d3 = d1 + d2;
                }
                if (count > 2) res = max(res, count);
            }
        return res;
    }
};