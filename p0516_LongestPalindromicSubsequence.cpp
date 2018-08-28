#include <iostream>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int i, j, slen;
        slen = s.size();
        if (slen == 0) { return 0; }
        int lps[slen][slen];
        for (i = slen - 1; i >= 0; i--) {
            for (j = i; j < slen; j++) {
                if (i == j) { lps[i][j] = 1; }
                else {
                    if (s[i] == s[j]) { lps[i][j] = ((i < j - 1) ? lps[i + 1][j - 1] : 0) + 2; }
                    else { lps[i][j] = max(lps[i + 1][j], lps[i][j - 1]); }
                }
            }
        }
        return lps[0][slen - 1];
    }
};
