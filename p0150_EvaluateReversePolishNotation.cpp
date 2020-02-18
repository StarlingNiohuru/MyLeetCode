#include <vector>
#include <stack>
#include <string>

using namespace std;

// Use a stack. Time complexity is O(n) and space complexity is O(n).
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        int n1, n2;
        for (string token:tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                n2 = stk.top();
                stk.pop();
                n1 = stk.top();
                stk.pop();
                if (token == "+") stk.push(n1 + n2);
                if (token == "-") stk.push(n1 - n2);
                if (token == "*") stk.push(n1 * n2);
                if (token == "/") stk.push(n1 / n2);

            } else stk.push(stoi(token));
        }
        return stk.top();
    }
};