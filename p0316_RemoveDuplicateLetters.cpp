#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Use a hash table lastPos<char,int> to record the last index of every character. Set visited<char> is used for removing
// duplicate char. Maintain a stack of final answer. When new char c<top() and top() is not the last one, it means we can
// find a better sequence. So we pop the top and push c into stack. Time complexity is O(n) and Space complexity is O(1).
class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stk;
        unordered_set<char> visited;
        unordered_map<char, int> lastPos;
        for (int i = 0; i < s.size(); i++) lastPos[s[i]] = i;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
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
