#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int res, i, j, t, hsize, nsize;
        hsize = haystack.size(), nsize = needle.size();
        if (nsize == 0) { return 0; };
        vector<int> table(nsize);
        table[0] = 0;
        for (j = 1; j < nsize; j++) {
            t = table[j - 1];
            while (t > 0 && needle[j] != needle[t]) { t = table[t - 1]; };
            if (needle[j] == needle[t]) { t++; }
            table[j] = t;
        }
        i = 0, j = 0;
        while (i < hsize) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                if (j > 0) {
                    j = table[j - 1];
                } else { i++; }
            }
            if (j == nsize) { return i - nsize; }
        }
        return -1;
    }
};
