#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) return true;
        if ((x < 0) || (x % 10 == 0)) return false;
        int temp = 0;
        while (x > temp) {
            temp = temp * 10 + x % 10;
            x = x / 10;
        }
        return (x == temp) || (x == temp / 10);
    }
};
