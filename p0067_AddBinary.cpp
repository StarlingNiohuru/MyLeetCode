#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        long i, j, m;
        int carry, temp;
        i = a.size() - 1, j = b.size() - 1, m = max(i, j) + 1, carry = 0;
        string res(m + 1, '0');
        while (i >= 0 || j >= 0 || carry) {
            temp = ((i >= 0) ? (a[i--] - '0') : 0) + ((j >= 0) ? (b[j--] - '0') : 0) + carry;
            res[m--] = temp % 2 + '0';
            carry = temp / 2;
        }
        auto start_num = res.find_first_not_of('0');
        if (res.size() > start_num) { return res.substr(start_num); }
        return "0";
    }
};
