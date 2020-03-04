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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode *> q;
        int count;
        q.push(root);
        while (!q.empty()) {
            count = q.size();
            TreeNode *curr = NULL;
            for (int i = 0; i < count; i++) {
                curr = q.front();
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            if (curr) res.push_back(curr->val);
        }
        return res;
    }
};