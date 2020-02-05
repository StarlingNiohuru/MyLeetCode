#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Iteration: Use a stack. Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *curr = root;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
        return res;
    }
};