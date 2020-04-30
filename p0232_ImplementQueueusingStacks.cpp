#include <stack>

using namespace std;

// Use 2 stacks. The main stack stores element with reverse order while the other is used for saving elements temporally
// when pushing. Time complexity of push() is O(n) and those of others are O(1). Space complexity is O(n).
class MyQueue {
public:
    stack<int> s, s2;

    MyQueue() {

    }

    void push(int x) {
        while (!s.empty()) {
            s2.push(s.top());
            s.pop();
        }
        s.push(x);
        while (!s2.empty()) {
            s.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        int f = s.top();
        s.pop();
        return f;
    }

    int peek() {
        return s.top();
    }

    bool empty() {
        return s.empty();
    }
};