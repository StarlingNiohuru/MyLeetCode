#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// similar to p0094. Because in-order traversal of BST can output a sort list, the answer is min(list[i]-list[i-1]).
// Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    int minDiffInBST(TreeNode *root) {
        int res = INT32_MAX, temp = NULL;
        stack<TreeNode *> stk;
        TreeNode *curr = root;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            if (temp)
                res = min(res, curr->val - temp);
            temp = curr->val;
            curr = curr->right;
        }
        return res;
    }
};