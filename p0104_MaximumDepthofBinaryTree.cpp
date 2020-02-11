#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// similar to p0102. BFS iteration. Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    int maxDepth(TreeNode *root) {
        int res = 0;
        if (!root) return res;
        queue<TreeNode *> q;
        int count;
        q.push(root);
        while (!q.empty()) {
            res++;
            count = q.size();
            for (int i = 0; i < count; i++) {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return res;
    }
};