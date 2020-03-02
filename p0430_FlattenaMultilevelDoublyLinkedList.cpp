using namespace std;

class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

// This problem can be transferred to binary tree(child as left and next as right). then similar to p0114.
// pre-order dfs recursion. Time complexity is O(n), space complexity is O(n).
class Solution {
private:
    void preorder(Node *curr, Node *&pre) {
        if (!curr) return;
        Node *c = curr->child, *n = curr->next;
        if (pre) {
            pre->child = NULL;
            pre->next = curr;
            curr->prev = pre;
        }
        pre = curr;
        preorder(c, pre);
        preorder(n, pre);
    }

public:
    Node *flatten(Node *head) {
        Node *pre = NULL;
        preorder(head, pre);
        return head;
    }
};