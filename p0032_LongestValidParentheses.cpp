#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
//        use stack to store index of '('. when encountering ')' pop
//        then record "index - top", the width of the longest continuous valid str. find the max at last
        int res = 0;
        stack<int> paren;
        paren.push(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') paren.push(i);
            else {
                paren.pop();
                if (paren.empty()) paren.push(i);
                else res = max(res, i - paren.top());
            }
        }
        return res;
    }
};