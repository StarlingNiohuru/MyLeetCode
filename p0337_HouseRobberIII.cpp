struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int rob(TreeNode *root) {
//        dfs return 2 values which respectively mean max rob sum without the root and one with root
        auto pair = dfs(root);
        return max(pair.first, pair.second);
    }

private:
    pair<int, int> dfs(TreeNode *node) {
        if (!node) return make_pair(0, 0);
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        int sum0 = max(left.first, left.second) + max(right.first, right.second);
        int sum1 = left.first + right.first + node->val;
        return make_pair(sum0, sum1);
    }
};