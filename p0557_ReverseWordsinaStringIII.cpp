#include <vector>

using namespace std;

// related to p0541. Time complexity is O(n).Space complexity is O(1).
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        for (int l = 0; l < n; l++)
            if (s[l] != ' ') {
                int r = l;
                while (r < n && s[r] != ' ') r++;
                for (int i = l, j = r - 1; i < j; i++, j--)
                    swap(s[i], s[j]);
                l = r;
            }
        return s;
    }
};
