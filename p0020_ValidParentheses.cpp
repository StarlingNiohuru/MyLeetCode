#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (char c:s) {
            switch (c) {
                case '[':
                    paren.push(']');
                    break;
                case '{':
                    paren.push('}');
                    break;
                case '(':
                    paren.push(')');
                    break;
                default:
                    if (!paren.empty() && c == paren.top()) paren.pop();
                    else return false;
            }
        }
        return paren.empty();
    }
};