#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// This problem is the same with p0316.
class Solution {
public:
    string smallestSubsequence(string text) {
        stack<char> stk;
        unordered_set<char> visited;
        unordered_map<char, int> lastPos;
        for (int i = 0; i < text.size(); i++) lastPos[text[i]] = i;
        for (int i = 0; i < text.size(); i++) {
            char c = text[i];
            if (visited.count(c) == 0) {
                while (!stk.empty() && c < stk.top() && lastPos[stk.top()] > i) {
                    visited.erase(stk.top());
                    stk.pop();
                }
                visited.insert(c);
                stk.push(c);
            }
        }
        string res;
        while (!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }
        return res;
    }
};