#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Iteration. Traverse all the element and find the second. Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    int findSecondMinimumValue(TreeNode *root) {
        int res = -1;
        bool isFirst = true;
        stack<TreeNode *> stk;
        TreeNode *curr = root;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            if (curr->val > root->val) {
                if (isFirst) {
                    res = curr->val;
                    isFirst = false;
                } else res = min(res, curr->val);
            }
            curr = curr->right;
        }
        return res;
    }
};