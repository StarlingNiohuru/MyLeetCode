#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int res, i, j, t, hsize, nsize;
        string haystack;
        while (haystack.size() < A.size() + B.size()) { haystack += A; }
        hsize = haystack.size(), nsize = B.size();
        if (nsize == 0) { return 0; };
        vector<int> table(nsize);
        table[0] = 0;
        for (j = 1; j < nsize; j++) {
            t = table[j - 1];
            while (t > 0 && B[j] != B[t]) { t = table[t - 1]; };
            if (B[j] == B[t]) { t++; }
            table[j] = t;
        }
        i = 0, j = 0;
        while (i < hsize) {
            if (haystack[i] == B[j]) {
                i++;
                j++;
            } else {
                if (j > 0) {
                    j = table[j - 1];
                } else { i++; }
            }
            if (j == nsize) { return (i - 1) / A.size() + 1; }
        }
        return -1;
    }
};
