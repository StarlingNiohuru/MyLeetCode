#include <stack>

using namespace std;

// Use 2 stacks
class MinStack {
    stack<int> stk;
    stack<int> minStk;
public:
    MinStack() {

    }

    void push(int x) {
        stk.push(x);
        if (minStk.empty() || x <= minStk.top()) minStk.push(x);
    }

    void pop() {
        if (stk.top() == minStk.top()) minStk.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
    }
};