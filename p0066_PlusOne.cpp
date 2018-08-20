#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res;
        int i, carry, temp;
        i = digits.size() - 1, carry = 0, digits[digits.size() - 1] += 1;
        while (i >= 0 || carry) {
            temp = digits[i--] + carry;
            res.push_back(temp % 10);
            carry = temp / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

