#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// dfs backtracking. related to p0112. Time complexity is O(n), space complexity is O(n).
class Solution {
private:
    void backtrack(vector<vector<int>> &res, vector<int> &path, int pathSum, TreeNode *root) {
        if (!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right && root->val == pathSum) res.push_back(path);
        backtrack(res, path, pathSum - root->val, root->left);
        backtrack(res, path, pathSum - root->val, root->right);
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(res, path, sum, root);
        return res;
    }
};