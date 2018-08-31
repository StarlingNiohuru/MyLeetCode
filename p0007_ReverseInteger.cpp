#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int digit;
        long long res = 0;
        while (x != 0) {
            digit = x % 10;
            res = res * 10 + digit;
            x = x / 10;
        }
        return (res < INT32_MIN || res > INT32_MAX) ? 0 : res;
    }
};
