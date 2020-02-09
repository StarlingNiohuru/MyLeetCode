#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// similar to p0102. Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> res;
        queue<TreeNode *> q;
        int count;
        double sum;
        q.push(root);
        while (!q.empty()) {
            count = q.size();
            sum = 0;
            for (int i = 0; i < count; i++) {
                TreeNode *curr = q.front();
                sum += curr->val;
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            res.push_back(sum / count);
        }
        return res;
    }
};