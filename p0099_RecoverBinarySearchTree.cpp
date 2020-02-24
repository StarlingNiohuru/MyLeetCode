#include <stack>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// similar to p0094. Use in-order traversal to output a sort list then find and swap the mistake numbers.
// Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *pre = NULL, *s1 = NULL, *s2 = NULL;
        bool s1Found = false;
        stack<TreeNode *> stk;
        TreeNode *curr = root;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            if (!s1Found) {
                if (pre && pre->val > curr->val) {
                    s1Found = true;
                    s1 = pre;
                    s2 = curr;
                }
            } else {
                if (pre->val > curr->val) {
                    s2 = curr;
                    break;
                }
            }
            pre = curr;
            curr = curr->right;
        }
        if (s1 && s2) swap(s1->val, s2->val);
    }
};