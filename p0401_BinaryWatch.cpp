#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        vector<int> hours, minutes;
        for (int h = 0; h < 5 && h <= num; h++) {
            hours = timeSums(h, false);
            minutes = timeSums(num - h, true);
            for (int i:hours) {
                for (int j:minutes) {
                    res.push_back(to_string(i) + (j < 10 ? ":0" : ":") + to_string(j));
                }
            }
        }
        return res;
    }

    vector<int> timeSums(int num, bool tType) {
        if (num == 0) { return {0}; }
        vector<int> res;
        int i = 0, maxValue, maxSum, sum;
        if (tType) {
            maxValue = (1 << 5);
            maxSum = 60;
        } else {
            maxValue = (1 << 3);
            maxSum = 12;
        };
        vector<int> s(num, 0);
        s[0] = 1;
        while (i >= 0) {
            if (i < num - 1) {
                if (s[i] < maxValue) {
                    s[i + 1] = s[i] << 1;
                    i++;
                } else {
                    i--;
                    if (i >= 0) { s[i] <<= 1; };
                }
            } else {
                sum = 0;
                for (int x:s) { sum += x; }
                if (sum < maxSum) { res.push_back(sum); }
                if (s[i] == maxValue) { i--; }
                if (i >= 0) { s[i] <<= 1; };
            }
        }
        return res;
    }
};
