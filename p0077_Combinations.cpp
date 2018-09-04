#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        int i = 0;
        vector<int> s(k, 0);
        s[0] = 1;
        while (i >= 0) {
            if (i < k - 1) {
                if (s[i] < n) {
                    s[i + 1] = s[i] + 1;
                    i++;
                } else {
                    i--;
                    if (i >= 0) { s[i]++; };
                }
            } else {
                res.push_back(s);
                if (s[i] == n) { i--; }
                if (i >= 0) { s[i]++; };
            }
        }
        return res;
    }
};
