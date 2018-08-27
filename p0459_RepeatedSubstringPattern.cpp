#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int res, i, t, size;
        size = s.size();
        if (size == 0) { return false; };
        vector<int> table(size);
        table[0] = 0;
        for (i = 1; i < size; i++) {
            t = table[i - 1];
            while (t > 0 && s[i] != s[t]) { t = table[t - 1]; };
            if (s[i] == s[t]) { t++; }
            table[i] = t;
        }
        return table[size - 1] && (table[size - 1] % (size - table[size - 1]) == 0);
    }
};

