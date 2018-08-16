#include <iostream>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool findTarget(TreeNode *root, int k) {
        unordered_set<int> set;
        return dfs(root, set, k);
    }

    bool dfs(TreeNode *root, unordered_set<int> &set, int k) {
        if (root == nullptr)return false;
        if (set.count(k - root->val))return true;
        set.insert(root->val);
        return dfs(root->left, set, k) || dfs(root->right, set, k);
    };
};
