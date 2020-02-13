#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// similar to p0094. next() and hasNext()'s time complexity is average O(1).
// Space complexity is O(h) where h is the max height of the tree.
class BSTIterator {
public:
    stack<TreeNode *> stk;

    BSTIterator(TreeNode *root) {
        TreeNode *curr = root;
        while (curr) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
        }
    }

    int next() {
        int res;
        TreeNode *curr = stk.top();
        stk.pop();
        res = curr->val;
        curr = curr->right;
        while (curr) {
            stk.push(curr);
            curr = curr->left;
        }
        return res;
    }

    bool hasNext() {
        return !stk.empty();
    }
};