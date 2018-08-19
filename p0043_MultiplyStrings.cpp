#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string res(num1.size() + num2.size(), '0');
        vector<int> sum(num1.size() + num2.size());
        int temp, carry;
        for (long int i = num1.size() - 1; i >= 0; --i) {
            carry = 0;
            for (long int j = num2.size() - 1; j >= 0; --j) {
                temp = (num1[i] - '0') * (num2[j] - '0') + carry;
                sum[i + j + 1] += temp % 10;
                carry = temp / 10;
            }
            sum[i] += carry;
        }
        carry = 0;
        for (long int i = sum.size() - 1; i >= 0; --i) {
            temp = sum[i] + carry;
            res[i] = temp % 10 + '0';
            carry = temp / 10;
        }
        auto start_num = res.find_first_not_of('0');
        cout << start_num << endl;
        if (res.size() > start_num) { return res.substr(start_num); }
        return "0";
    }
};
