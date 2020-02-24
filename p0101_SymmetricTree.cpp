using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// recursion. Time complexity is O(n), space complexity is O(n).
class Solution {
private:
    bool isMirror(TreeNode *t1, TreeNode *t2) {
        if (!t1 || !t2) return t1 == t2;
        return t1->val == t2->val && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }

public:
    bool isSymmetric(TreeNode *root) {
        return isMirror(root, root);
    }
};