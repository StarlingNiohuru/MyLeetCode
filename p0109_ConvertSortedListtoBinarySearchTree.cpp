#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// similar to p0108. Use 2 pointers (fast and slow) to find the middle node.
// Time complexity is O(n), space complexity is O(n).
class Solution {
private:
    TreeNode *build(ListNode *start) {
        if (!start) return NULL;
        ListNode *fast = start, *slow = start, *stop1;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            stop1 = slow;
            slow = slow->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        if (slow->next) {
            if (slow != start) {
                stop1->next = NULL;
                root->left = build(start);
            }
            root->right = build(slow->next);
        }
        return root;
    }

public:
    TreeNode *sortedListToBST(ListNode *head) {
        return build(head);
    }
};