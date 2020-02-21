#include <stack>
#include <cctype>

using namespace std;

// Use 2 stacks. One is used to record operators while another is for numbers. When meet '+','-' or '(' push former
// numbers and operators into each stack. When meet ')', pop and calculate from 2 stacks until meet '(' then push the
// sum into stack. At last pop and calculate all from 2 stacks. Time complexity is O(n) and space complexity is O(n).
class Solution {
public:
    int calculate(string s) {
        stack<char> operators;
        stack<int> numbers;
        s += '#';
        int res = 0, temp = 0, last;
        for (char c:s) {
            if (isdigit(c)) {
                if (operators.empty() || operators.top() == '(') operators.push('+');
                temp = temp * 10 + (c - '0');
            } else if (!isspace(c)) {
                if (c == ')') {
                    last = 0;
                    numbers.push(temp);
                    while (operators.top() != '(') {
                        if (operators.top() == '+') last += numbers.top();
                        else last -= numbers.top();
                        operators.pop();
                        numbers.pop();
                    }
                    operators.pop();
                    temp = last;
                } else {
                    if (operators.empty() || operators.top() == '(') operators.push('+');
                    operators.push(c);
                    if (c != '(') numbers.push(temp);
                    temp = 0;
                }
            }
        }
        operators.pop();
        while (!numbers.empty()) {
            if (operators.top() == '+') res += numbers.top();
            else res -= numbers.top();
            operators.pop();
            numbers.pop();
        }
        return res;
    }
};
