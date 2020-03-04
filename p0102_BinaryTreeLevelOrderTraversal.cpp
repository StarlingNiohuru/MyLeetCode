#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// BFS iteration with a queue. Use a counter to record the number of every level.
// Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> row;
        queue<TreeNode *> q;
        int count;
        q.push(root);
        while (!q.empty()) {
            count = q.size();
            for (int i = 0; i < count; i++) {
                TreeNode *curr = q.front();
                row.push_back(curr->val);
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            res.push_back(row);
            row.clear();
        }
        return res;
    }
};

// dfs recursion.
class Solution2 {
private:
    void level(vector<vector<int>> &res, TreeNode *root, int depth) {
        if (!root) return;
        if (res.size() == depth) res.emplace_back();
        res[depth].push_back(root->val);
        level(res, root->left, depth + 1);
        level(res, root->right, depth + 1);
    }

public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        level(res, root, 0);
        return res;
    }
};