#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long res = 0;
        int sign = 1;
        int i = str.find_first_not_of(' ');
        if (str[i] == '-' || str[i] == '+') { sign = (str[i++] == '-') ? -1 : 1; }
        while (str[i] >= '0' && str[i] <= '9') {
            res = res * 10 + (str[i++] - '0');
            if (sign * res >= INT32_MAX) return INT32_MAX;
            if (sign * res <= INT32_MIN) return INT32_MIN;
        }
        return sign * res;
    }
};
