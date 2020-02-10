#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Iteration with a stack. Push every left child into stack until left=NULL. Then step back and check right child. When
// a node has no right child or right child has been visited, record the value and pop from stack. Time complexity is
// O(n), space complexity is O(n).
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *curr = root, *temp = NULL, *last = NULL;
        while (curr || !stk.empty()) {
            if (curr) {
                stk.push(curr);
                curr = curr->left;
            } else {
                temp = stk.top();
                if (temp->right && temp->right != last) curr = temp->right;
                else {
                    res.push_back(temp->val);
                    last = temp;
                    stk.pop();
                }
            }
        }
        return res;
    }
};