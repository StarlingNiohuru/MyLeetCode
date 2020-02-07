#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// similar to p0094. Use in-order traversal of BST to output a sort list, Then count to find modes.
// Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    vector<int> findMode(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        int pre = INT32_MAX, count = 1, maxCount = 0;
        stack<TreeNode *> stk;
        TreeNode *curr = root;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            if (pre == INT32_MAX) pre = curr->val;
            else if (curr->val == pre) count++;
            else {
                if (count > maxCount) {
                    while (!res.empty()) res.pop_back();
                    maxCount = count;
                    res.push_back(pre);
                } else if (count == maxCount)
                    res.push_back(pre);
                count = 1;
                pre = curr->val;
            }
            curr = curr->right;
        }
        if (count > maxCount) {
            while (!res.empty()) res.pop_back();
            res.push_back(pre);
        } else if (count == maxCount)
            res.push_back(pre);
        return res;
    }
};