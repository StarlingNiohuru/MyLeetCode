using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// recursion. Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        else if (!root->left && !root->right) return sum == root->val;
        else return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};