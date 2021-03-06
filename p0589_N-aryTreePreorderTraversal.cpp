#include <stack>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

// similar to p0144. Iteration: Pop every element from top and record the value. Then push all of its children into
// stack reversely. Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    vector<int> preorder(Node *root) {
        vector<int> res;
        if (!root) return res;
        stack<Node *> stk;
        stk.push(root);
        while (!stk.empty()) {
            Node *curr = stk.top();
            res.push_back(curr->val);
            stk.pop();
            for (int i = curr->children.size() - 1; i >= 0; i--)
                if (curr->children[i]) stk.push(curr->children[i]);
        }
        return res;
    }
};
