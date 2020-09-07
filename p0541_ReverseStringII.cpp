#include <vector>

using namespace std;

// related to p0344. Reverse every range like (0k-1k,2k-3k,4k-5k....) with 2 pointers.
// Time complexity is O(n).Space complexity is O(1).
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int l = 0; l < n; l += 2 * k)
            for (int i = l, j = min(l + k - 1, n - 1); i < j; i++, j--)
                swap(s[i], s[j]);
        return s;
    }
};