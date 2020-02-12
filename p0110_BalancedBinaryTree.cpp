using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive way.Time complexity is O(n), space complexity is O(n).
class Solution {
private:
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

public:
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        int d = maxDepth(root->left) - maxDepth(root->right);
        return d <= 1 && d >= -1 && isBalanced(root->left) && isBalanced(root->right);
    }
};