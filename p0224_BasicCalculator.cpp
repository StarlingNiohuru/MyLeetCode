#include <stack>
#include <cctype>

using namespace std;

// Use 2 stacks. One is used to record operands while another is for numbers. When meet '+','-' or '(' push former
// number and operand into each stack. When meet ')', pop and calculate from 2 stacks until meet '(' then push the sum
// into stack. At last pop and calculate all from 2 stacks. Time complexity is O(n) and space complexity is O(n).
class Solution {
public:
    int calculate(string s) {
        stack<char> operand;
        stack<int> number;
        s += '#';
        int res = 0, temp = 0, last;
        for (char c:s) {
            if (isdigit(c)) {
                if (operand.empty() || operand.top() == '(') operand.push('+');
                temp = temp * 10 + (c - '0');
            } else if (!isspace(c)) {
                if (c == ')') {
                    last = 0;
                    number.push(temp);
                    while (operand.top() != '(') {
                        if (operand.top() == '+') last += number.top();
                        else last -= number.top();
                        operand.pop();
                        number.pop();
                    }
                    operand.pop();
                    temp = last;
                } else {
                    if (operand.empty() || operand.top() == '(') operand.push('+');
                    operand.push(c);
                    if (c != '(') number.push(temp);
                    temp = 0;
                }
            }
        }
        operand.pop();
        while (!number.empty()) {
            if (operand.top() == '+') res += number.top();
            else res -= number.top();
            operand.pop();
            number.pop();
        }
        return res;
    }
};
