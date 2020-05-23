using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Time complexity is O(n). Space complexity is O(n).
class Solution {
public:
    string tree2str(TreeNode *t) {
        if (!t) return "";
        if (!t->left && !t->right) return to_string(t->val);
        if (t->left && !t->right) return to_string(t->val) + '(' + tree2str(t->left) + ')';
        else return to_string(t->val) + '(' + tree2str(t->left) + ")(" + tree2str(t->right) + ')';
    }
};