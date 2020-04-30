#include <queue>

using namespace std;

// Use one queue with reverse order and rotate the queue when pushing. Time complexity of push() is O(n) and those of
// others are O(1). Space complexity is O(n).
class MyStack {
public:
    queue<int> q;

    MyStack() {
    }

    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int f = q.front();
        q.pop();
        return f;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};