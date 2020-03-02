using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// pre-order dfs recursion. Time complexity is O(n), space complexity is O(1).
class Solution {
private:
    void preorder(TreeNode *root, TreeNode *&pre) {
        if (!root) return;
        TreeNode *l = root->left, *r = root->right;
        if (pre) {
            pre->left = NULL;
            pre->right = root;
        }
        pre = root;
        preorder(l, pre);
        preorder(r, pre);
    }

public:
    void flatten(TreeNode *root) {
        TreeNode *pre = NULL;
        preorder(root, pre);
    }
};