#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// similar to p0102. BFS iteration with a queue. Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    bool isCousins(TreeNode *root, int x, int y) {
        if (!root) return false;
        queue<TreeNode *> q;
        int count, countChildren = 0, parent1 = 0, parent2 = 0;
        q.push(root);
        while (!q.empty()) {
            count = q.size();
            for (int i = 0; i < count; i++) {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                if (curr->left && (curr->left->val == x || curr->left->val == y)) {
                    parent1 = curr->val;
                    countChildren++;
                }
                if (curr->right && (curr->right->val == x || curr->right->val == y)) {
                    parent2 = curr->val;
                    countChildren++;
                }
            }
            if (countChildren == 2 && parent1 != parent2) return true;
            else if (countChildren > 0) return false;
        }
        return false;
    }
};
