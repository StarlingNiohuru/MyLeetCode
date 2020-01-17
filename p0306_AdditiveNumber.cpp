#include <string>

using namespace std;

// First we need to confirm the first and second nums of Fibonacci sequence. Then we can check whether the rest of
// string is valid. Time complexity is O(n^3).
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int i = 1; i <= n / 2; i++) {
            string s1 = num.substr(0, i);
            if (s1.size() > 1 && s1[0] == '0') break;
            for (int j = 1; j <= (n - i) / 2; j++) {
                string s2 = num.substr(i, j);
                if ((s2.size() > 1 && s2[0] == '0')) break;
                if (i + j == n) break;
                long d1 = stol(s1), d2 = stol(s2), d3 = d1 + d2;
                string s3 = to_string(d3);
                int l = s3.size(), k = i + j;
                while (k + l <= n && s3 == num.substr(k, l)) {
                    k += l;
                    d1 = d2;
                    d2 = d3;
                    d3 = d1 + d2;
                    s3 = to_string(d3);
                    l = s3.size();
                }
                if (k == n) return true;
            }
        }
        return false;
    }
};