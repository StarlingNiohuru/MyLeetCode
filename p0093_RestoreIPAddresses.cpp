#include <vector>
#include <string>

using namespace std;

// dfs backtracking. Cut s into length 1,2 or 3 and check the substring on every step.
// Time complexity is O(1). Space complexity is O(1).
class Solution {
private:
    bool isValid(string s) {
        if (s.empty() || s.size() > 3) return false;
        if (s.size() >= 2 && s[0] == '0') return false;
        return stoi(s) < 256;
    }

private:
    void backtrack(string &s, vector<string> &res, vector<string> &ip, int i) {
        if (ip.size() == 4) {
            if (i == s.size()) {
                string r;
                for (string a:ip)
                    r += (a + '.');
                r.pop_back();
                res.push_back(r);
            }
            return;
        }
        for (int len = 1; len <= 3; len++) {
            if (i + len <= s.size()) {
                string ss = s.substr(i, len);
                if (isValid(ss)) {
                    ip.push_back(ss);
                    backtrack(s, res, ip, i + len);
                    ip.pop_back();
                }
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> ip;
        backtrack(s, res, ip, 0);
        return res;
    }
};