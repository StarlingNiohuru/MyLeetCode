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

// similar to p0145. Iteration. Use stack with pair<node,index>. Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    vector<int> postorder(Node *root) {
        vector<int> res;
        if (!root) return res;
        stack<pair<Node *, int>> stk;
        stk.push({root, 0});
        Node *curr;
        while (!stk.empty()) {
            auto &temp = stk.top();
            curr = temp.first;
            int &i = temp.second;
            if (i < curr->children.size())
                stk.push({curr->children[i++], 0});
            else {
                res.push_back(curr->val);
                stk.pop();
            }
        }
        return res;
    }
};