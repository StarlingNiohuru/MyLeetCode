#include <vector>

using namespace std;

// dfs backtracking. Divide the string and check whether the front half is palindrome. If so, put the rest of string to
// backtrack until reaching end. Time complexity is O(n*2^n). Space complexity is O(n*2^n).
class Solution {
private:
    void backtrack(vector<vector<string>> &res, vector<string> &r, string s) {
        if (s.empty()) {
            res.push_back(r);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            string s1 = s.substr(0, i + 1);
            if (isPalindrome(s1)) {
                r.push_back(s1);
                backtrack(res, r, s.substr(i + 1));
                r.pop_back();
            }
        }
    }

    bool isPalindrome(string s) {
        if (s.empty()) return false;
        int start = 0, stop = s.size() - 1;
        while (start <= stop) if (s[start++] != s[stop--]) return false;
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> r;
        backtrack(res, r, s);
        return res;
    }
};

