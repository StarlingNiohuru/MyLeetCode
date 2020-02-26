#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// recursion. similar to p0105. Because of post-order, we traverse root index and build new node from right to left.
// Time complexity is O(n), space complexity is O(n).
class Solution {
private:
    TreeNode *build(vector<int> &inorder, vector<int> &postorder, int &rootIndex, int start, int stop) {
        if (rootIndex < 0 || start > stop) return NULL;
        TreeNode *root = new TreeNode(postorder[rootIndex]);
        auto r = find(inorder.begin() + start, inorder.begin() + stop, postorder[rootIndex]);
        int rootPos = distance(inorder.begin(), r);
        rootIndex--;
        root->right = build(inorder, postorder, rootIndex, rootPos + 1, stop);
        root->left = build(inorder, postorder, rootIndex, start, rootPos - 1);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int rootIndex = postorder.size() - 1;
        return build(inorder, postorder, rootIndex, 0, inorder.size() - 1);
    }
};