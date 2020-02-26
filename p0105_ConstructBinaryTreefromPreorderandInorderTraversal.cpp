#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// The first element of pre-order must be root. We use root to divide in-order into left and right trees. Then move to
// the next pre-order element and repeat the process above with left and right trees.
// Time complexity is O(n), space complexity is O(n).
class Solution {
private:
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int &rootIndex, int start, int stop) {
        if (rootIndex == preorder.size() || start > stop) return NULL;
        TreeNode *root = new TreeNode(preorder[rootIndex]);
        auto r = find(inorder.begin() + start, inorder.begin() + stop, preorder[rootIndex]);
        int rootPos = distance(inorder.begin(), r);
        rootIndex++;
        root->left = build(preorder, inorder, rootIndex, start, rootPos - 1);
        root->right = build(preorder, inorder, rootIndex, rootPos + 1, stop);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int rootIndex = 0;
        return build(preorder, inorder, rootIndex, 0, inorder.size() - 1);
    }
};