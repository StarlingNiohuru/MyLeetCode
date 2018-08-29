#include <iostream>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int i, j, res, strlen;
        res = 0, strlen = s.size();
        for (i = 0; i < strlen; i++) {
            j = 0;
            while ((i - j >= 0) && (i + j < strlen) && (s[i - j] == s[i + j])) {
                j++;
                res += 1;
            }
            j = 0;
            while ((i - j >= 0) && (i + j + 1 < strlen) && (s[i - j] == s[i + j + 1])) {
                j++;
                res += 1;
            }
        }
        return res;
    }
};
