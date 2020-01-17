#include <vector>
#include <string>

using namespace std;

// similar to p0306. Make sure every number not over INT32_MAX. Time complexity is O(n^3).
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> res = {};
        int n = S.size();
        for (int i = 1; i <= n / 2 && i < 11; i++) {
            string s1 = S.substr(0, i);
            if (s1.size() > 1 && s1[0] == '0') break;
            for (int j = 1; j <= (n - i) / 2 && j < 11; j++) {
                string s2 = S.substr(i, j);
                if ((s2.size() > 1 && s2[0] == '0')) break;
                if (i + j == n) break;
                long d1 = stol(s1), d2 = stol(s2), d3 = d1 + d2;
                if (d1 > INT32_MAX || d2 > INT32_MAX) break;
                res = {d1, d2};
                string s3 = to_string(d3);
                int l = s3.size(), k = i + j;
                while (k + l <= n && s3 == S.substr(k, l) && d3 <= INT32_MAX) {
                    res.push_back(d3);
                    k += l;
                    d1 = d2;
                    d2 = d3;
                    d3 = d1 + d2;
                    s3 = to_string(d3);
                    l = s3.size();
                }
                if (k == n) return res;
            }
        }
        return {};
    }
};

