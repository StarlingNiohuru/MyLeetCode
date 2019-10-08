#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

//BFS, try every possibility, set is used to remove duplicates
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        queue<string> q;
        unordered_set<string> visited;
        q.push(s);
        visited.insert(s);
        bool validFound = false;
        while (!q.empty()) {
            string s = q.front();
            q.pop();
            if (isValid(s)) {
                res.push_back(s);
                validFound = true;
            }
            if (validFound) continue;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] != '(' && s[i] != ')') continue;
                string t = s.substr(0, i) + s.substr(i + 1);
                if (visited.count(t) == 0) {
                    q.push(t);
                    visited.insert(t);
                }
            }
        }
        return res;
    }

private:
    bool isValid(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') count++;
            if (s[i] == ')') count--;
            if (count < 0) return false;
        }
        return count == 0;
    }
};