#include <vector>

using namespace std;

// Use XOR (^) operator.
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = t[0];
        for (int i = 0; i < s.size(); i++)
            res ^= s[i] ^ t[i + 1];
        return res;
    }
};