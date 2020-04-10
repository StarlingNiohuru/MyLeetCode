#include <vector>
#include <algorithm>

using namespace std;

// Convert the nums to string and rewrite the comp() function. When s1+s2>s2+s1, s1 should be in front of s2.
// Time complexity is O((k*n*log(n)) where k is the average length of string, space complexity is O(n).
class Solution {
public:
    string largestNumber(vector<int> &nums) {
        vector<string> digits;
        for (int num:nums) digits.push_back(to_string(num));
        sort(digits.begin(), digits.end(), [](string &s1, string &s2) { return s1 + s2 > s2 + s1; });
        string res;
        for (string digit:digits) res += digit;
        while (res[0] == '0' && res.length() > 1) res.erase(0, 1);
        return res;
    }
};