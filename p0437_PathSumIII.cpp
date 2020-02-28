#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// dfs recursion. Time complexity is O(n^2), space complexity is O(n).
class Solution {
private:
    void backtrack(int &count, TreeNode *root, int pathSum) {
        if (!root) return;
        if (root->val == pathSum) count++;
        backtrack(count, root->left, pathSum - root->val);
        backtrack(count, root->right, pathSum - root->val);
    }

    int pathSumFromRoot(TreeNode *root, int sum) {
        int count = 0;
        backtrack(count, root, sum);
        return count;
    }

public:
    int pathSum(TreeNode *root, int sum) {
        if (!root) return 0;
        return pathSumFromRoot(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};