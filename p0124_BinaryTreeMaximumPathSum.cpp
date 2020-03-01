using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// similar to p0687. Time complexity is O(n), space complexity is O(n).
class Solution {
private:
    int maxPathFromRoot(TreeNode *root, int &mps) {
        if (!root) return 0;
        int l = max(maxPathFromRoot(root->left, mps), 0);
        int r = max(maxPathFromRoot(root->right, mps), 0);
        mps = max(mps, l + r + root->val);
        return max(l, r) + root->val;
    }

public:
    int maxPathSum(TreeNode *root) {
        int res = INT32_MIN;
        maxPathFromRoot(root, res);
        return res;
    }
};