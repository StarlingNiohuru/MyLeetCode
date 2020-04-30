using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// recursive. Time complexity is O(n) and space complexity is O(n).
class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (!root) return NULL;
        TreeNode *invertedLeft = invertTree(root->left);
        TreeNode *invertedRight = invertTree(root->right);
        root->left = invertedRight;
        root->right = invertedLeft;
        return root;
    }
};