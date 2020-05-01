using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//recursive. Because of BST, if node<p and node<q, node.right must be their common ancestor. Vice versa.
//Time complexity is O(n) and space complexity is O(n).
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        if (root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};