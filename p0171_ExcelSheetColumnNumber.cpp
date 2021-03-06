using namespace std;

// related to p0168.
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (char c : s) res = res * 26 + (c - 'A' + 1);
        return res;
    }
};