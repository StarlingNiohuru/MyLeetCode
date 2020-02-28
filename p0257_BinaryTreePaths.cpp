#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// dfs backtracking. similar to p0113. Time complexity is O(n), space complexity is O(n).
class Solution {
private:
    void backtrack(vector<string> &res, string path, TreeNode *root) {
        if (!root) return;
        path += (!path.empty()) ? "->" + to_string(root->val) : to_string(root->val);
        if (!root->left && !root->right) res.push_back(path);
        backtrack(res, path, root->left);
        backtrack(res, path, root->right);
    }

public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> res;
        backtrack(res, "", root);
        return res;
    }
};