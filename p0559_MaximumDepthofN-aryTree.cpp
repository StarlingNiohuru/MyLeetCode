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

// similar to p0102 and p0104. BFS iteration. Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    int maxDepth(Node *root) {
        int res = 0;
        if (!root) return res;
        queue<Node *> q;
        int count;
        q.push(root);
        while (!q.empty()) {
            res++;
            count = q.size();
            for (int i = 0; i < count; i++) {
                Node *curr = q.front();
                q.pop();
                for (int j = 0; j < curr->children.size(); j++)
                    if (curr->children[j]) q.push(curr->children[j]);
            }
        }
        return res;
    }
};