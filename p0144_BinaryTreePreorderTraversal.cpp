#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Iteration: Pop every element from top and record the value. Then push the right and the left child into stack.
// Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *curr = stk.top();
            res.push_back(curr->val);
            stk.pop();
            if (curr->right) stk.push(curr->right);
            if (curr->left) stk.push(curr->left);
        }
        return res;
    }
};

// DFS iteration: Use a stack. Time complexity is O(n), space complexity is O(n).
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *curr = root;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                res.push_back(curr->val);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            curr = curr->right;
        }
        return res;
    }
};

// dfs recursion.
class Solution3 {
private:
    void preorder(vector<int> &res, TreeNode *root) {
        if (!root) return;
        res.push_back(root->val);
        preorder(res, root->left);
        preorder(res, root->right);
    }

public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        preorder(res, root);
        return res;
    }
};