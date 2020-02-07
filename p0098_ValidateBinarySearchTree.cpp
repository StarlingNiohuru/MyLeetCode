#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// similar to p0094. Use in-order traversal of BST to output a list, Then check whether the list is strictly increasing.
// Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        int pre = 0;
        bool isFirst = true;
        stack<TreeNode *> stk;
        TreeNode *curr = root;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            if (isFirst) {
                pre = curr->val;
                isFirst = false;
            } else if (curr->val <= pre) return false;
            else pre = curr->val;
            curr = curr->right;
        }
        return true;
    }
};