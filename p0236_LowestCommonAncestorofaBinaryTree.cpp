using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// recursive. We use the recursive function by this way: To every node, if p and q both exist below, return the LCA;
// if only p or q exists, return p or q; if neither of them exists, return None. Then the result below can be sent upward.
// Time complexity is O(n) and space complexity is O(n).
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || root == p || root == q) return root;
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        if (!l) return r;
        else if (!r) return l;
        else return root;
    }
};