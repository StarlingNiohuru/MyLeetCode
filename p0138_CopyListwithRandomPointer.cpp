#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// 2 times of traversal with a hash map. Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (!head) return NULL;
        unordered_map<Node *, Node *> nodePair;
        Node *curr = head;
        nodePair[curr] = new Node(curr->val);
        Node *res = nodePair[curr];
        while (curr->next) {
            nodePair[curr->next] = new Node(curr->next->val);
            nodePair[curr]->next = nodePair[curr->next];
            curr = curr->next;
        }
        curr = head;
        while (curr) {
            if (curr->random) nodePair[curr]->random = nodePair[curr->random];
            curr = curr->next;
        }
        return res;
    }
};