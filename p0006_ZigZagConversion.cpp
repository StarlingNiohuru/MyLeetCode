#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 0 || numRows == 1) { return s; }
        string res;
        int i, j, k, size;
        size = s.size();
        for (i = 0; i < numRows; i++) {
            j = i;
            k = 0;
            while (j < size) {
                res += s[j];
                if (i == 0 || i == numRows - 1) { j += 2 * (numRows - 1); }
                else {
                    if (k % 2 == 0) { j += 2 * (numRows - 1 - i); } else { j += 2 * i; }
                    k += 1;
                }
            }
        }
        return res;
    }
};
