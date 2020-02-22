#include <vector>

using namespace std;

// dfs backtracking. Every step we need to record 2 nums, pre and cur, and a char operator.
// Use them with the new number to calculate new pre and cur. Then pass then with new operator to next step.
// Time complexity is O(4^n). Space complexity is O(n).
class Solution {
private:
    void
    backtrack(vector<string> &res, string &num, int &target, string expression, int i, long pre, char op, long cur) {
        long newPre;
        if (op == '+') newPre = pre + cur;
        else if (op == '-') newPre = pre - cur;
        else newPre = pre * cur;
        if (i == num.size()) {
            if (newPre == target) res.push_back(expression);
        } else {
            for (int j = i; j < num.size(); j++) {
                string s = num.substr(i, j - i + 1);
                if (to_string(stol(s)).size() != s.size()) break;
                if (op == '#')
                    backtrack(res, num, target, s, j + 1, 1, '*', stol(s));
                else {
                    backtrack(res, num, target, expression + '+' + s, j + 1, newPre, '+', stol(s));
                    backtrack(res, num, target, expression + '-' + s, j + 1, newPre, '-', stol(s));
                    backtrack(res, num, target, expression + '*' + s, j + 1, (op == '*') ? newPre : pre,
                              (op == '*') ? '*' : op, (op == '*') ? stol(s) : cur * stol(s));
                }
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        backtrack(res, num, target, "", 0, 0, '#', 0);
        return res;
    }
};