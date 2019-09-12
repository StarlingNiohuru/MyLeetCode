#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())return {};
        vector<string> res;
        unordered_map<char, string> map = {{'2', "abc"},
                                           {'3', "def"},
                                           {'4', "ghi"},
                                           {'5', "jkl"},
                                           {'6', "mno"},
                                           {'7', "pqrs"},
                                           {'8', "tuv"},
                                           {'9', "wxyz"}};
//        backtracking dfs implemented by iteration, s is stack, i is the index of stack
        int i = 0;
        string s(digits.size(), '-');
        while (i >= 0) {
            if (i < digits.size()) {
                if (digits[i] < '2' || digits[i] > '9') return {};
                if (s[i] == '-') {
                    s[i] = map[digits[i]][0];
                    i++;
                } else if (s[i] < map[digits[i]].back()) {
                    s[i] = s[i] + 1;
                    i++;
                } else {
                    s[i] = '-';
                    i--;
                }
            } else {
                res.push_back(s);
                i--;
            }
        }
        return res;
    }
};