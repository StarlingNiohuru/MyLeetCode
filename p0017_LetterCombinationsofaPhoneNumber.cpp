#include <vector>
#include <unordered_map>

using namespace std;

//better and clear iteration like bfs
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
        res.push_back("");
//        res1 is the result of digits[0:-2],use res1 to generate res
        for (int i = 0; i < digits.size(); i++) {
            vector<string> res1;
            string chars = map[digits[i]];
            for (int j = 0; j < res.size(); j++)
                for (int k = 0; k < chars.size(); k++)
                    res1.push_back(res[j] + chars[k]);
            res = res1;
        }
        return res;
    }
};

//poor dfs iteration
class Solution2 {
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