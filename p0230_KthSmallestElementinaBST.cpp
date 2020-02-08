#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// similar to p0094. Because in-order traversal of BST can output a sort list, we can find the Kth element.
// Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        int count = 0;
        stack<TreeNode *> stk;
        TreeNode *curr = root;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            count++;
            if (count == k) return curr->val;
            curr = curr->right;
        }
        return 0;
    }
};