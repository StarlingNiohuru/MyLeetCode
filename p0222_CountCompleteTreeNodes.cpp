using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// recursion. Time complexity is O(n) and space complexity is O(log(n)).
class Solution {
public:
    int countNodes(TreeNode *root) {
        return root ? (1 + countNodes(root->left) + countNodes(root->right)) : 0;
    }
};