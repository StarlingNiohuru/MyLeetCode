#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int i, j, start, reslen, templen, strlen;
        start = 0, reslen = 0, strlen = s.size();
        for (i = 0; i < strlen; i++) {
            j = 0;
            while ((i - j >= 0) && (i + j < strlen) && (s[i - j] == s[i + j])) {
                j++;
            }
            templen = (j - 1) * 2 + 1;
            if (i + 1 < strlen && s[i] == s[i + 1]) {
                j = 1;
                while ((i - j >= 0) && (i + j + 1 < strlen) && (s[i - j] == s[i + j + 1])) {
                    j++;
                }
                templen = max(templen, (j - 1) * 2 + 2);
            }
            if (templen > reslen) {
                start = i - (templen - 1) / 2;
                reslen = templen;
            }
        }
        return s.substr(start, reslen);
    }
};
