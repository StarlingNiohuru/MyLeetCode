#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        int size, sizeNew, i, t;
        size = s.size();
        string rev(s);
        reverse(rev.begin(), rev.end());
        string sNew = s + "#" + rev;
        sizeNew = sNew.size();
        vector<int> table(sizeNew);
        table[size - 1] = 0;
        for (i = 1; i < sizeNew; i++) {
            t = table[i - 1];
            while (t > 0 && sNew[i] != sNew[t]) { t = table[t - 1]; }
            if (sNew[i] == sNew[t]) { ++t; }
            table[i] = t;
        }
        return rev.substr(0, size - table[sizeNew - 1]) + s;
    }
};
