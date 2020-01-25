#include <vector>
#include <string>

using namespace std;

// Use binary digits to represent every state. bitIndex[] is used to store indexes of string S.
// Time complexity is O(n*2^n) where n is the number of characters in string S.
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        vector<int> bitIndex;
        for (int i = 0; i < S.size(); i++)
            if (('A' <= S[i] && S[i] <= 'Z') || ('a' <= S[i] && S[i] <= 'z'))
                bitIndex.push_back(i);
        int maxDecNum = 1;
        for (int i = 0; i < bitIndex.size(); i++) maxDecNum *= 2;
        for (int b = 0; b < maxDecNum; b++) {
            string s = S;
            int biDigit = b;
            for (int j : bitIndex) {
                if (biDigit & 1) s[j] = toupper(s[j]);
                else s[j] = tolower(s[j]);
                biDigit >>= 1;
            }
            res.push_back(s);
        }
        return res;
    }
};