#include <queue>

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

// similar to p0102. BFS iteration. Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> row;
        queue<Node *> q;
        int count;
        q.push(root);
        while (!q.empty()) {
            count = q.size();
            for (int i = 0; i < count; i++) {
                Node *curr = q.front();
                row.push_back(curr->val);
                q.pop();
                for (int j = 0; j < curr->children.size(); j++)
                    if (curr->children[j]) q.push(curr->children[j]);
            }
            res.push_back(row);
            row.clear();
        }
        return res;
    }
};