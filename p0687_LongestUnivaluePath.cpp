using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// dfs recursion. First we need to calculate the longest uni-value path (from root to only one node below) by
// post-order dfs traversal. At the same time use a reference to find the max of longest uni-value path of each step.
// Time complexity is O(n), space complexity is O(n).
class Solution {
private:
    int longestPathFromRoot(TreeNode *root, int &lup) {
        if (!root) return 0;
        int l = root->left ? longestPathFromRoot(root->left, lup) : 0;
        int r = root->right ? longestPathFromRoot(root->right, lup) : 0;
        int lp = (root->left && root->val == root->left->val) ? (l + 1) : 0;
        int rp = (root->right && root->val == root->right->val) ? (r + 1) : 0;
        lup = max(lup, lp + rp);
        return max(lp, rp);
    }

public:
    int longestUnivaluePath(TreeNode *root) {
        int res = 0;
        longestPathFromRoot(root, res);
        return res;
    }
};