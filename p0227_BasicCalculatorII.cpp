#include <stack>
#include <cctype>

using namespace std;

// Use a stack. When meet '+' or '-' push the number into stack. When meet '*' or '/', pop and calculate then push new
// result into stack. The sum is the answer. Time complexity is O(n) and space complexity is O(n).
class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        s += '+';
        char sign = '+';
        int res = 0, temp = 0, last;
        for (char c:s) {
            if (isdigit(c)) temp = temp * 10 + (c - '0');
            else if (!isspace(c)) {
                if (sign == '+') stk.push(temp);
                else if (sign == '-') stk.push(-temp);
                else {
                    if (sign == '*') last = stk.top() * temp;
                    else last = stk.top() / temp;
                    stk.pop();
                    stk.push(last);
                }
                sign = c;
                temp = 0;
            }
        }
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};