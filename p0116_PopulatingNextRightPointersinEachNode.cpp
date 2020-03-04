#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

// similar to p0102. BFS iteration with a queue. Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    Node *connect(Node *root) {
        if (!root) return NULL;
        queue<Node *> q;
        int count;
        q.push(root);
        while (!q.empty()) {
            Node *pre = NULL;
            count = q.size();
            for (int i = 0; i < count; i++) {
                Node *curr = q.front();
                if (pre) pre->next = curr;
                pre = curr;
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return root;
    }
};