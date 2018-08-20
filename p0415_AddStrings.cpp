#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int i, j, temp, carry;
        carry = 0, i = num1.size() - 1, j = num2.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            temp = ((i >= 0) ? (num1[i--] - '0') : 0) + ((j >= 0) ? (num2[j--] - '0') : 0) + carry;
            res.push_back(temp % 10 + '0');
            carry = temp / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
