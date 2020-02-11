#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Iteration. Use stack with pairs<node,index>. index represents next operation. It's a more clear way than solution 2
// and it can be generalized to N-ary Tree. But it uses more space. Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        stack<pair<TreeNode *, int>> stk;
        stk.push({root, 0});
        TreeNode *curr;
        while (!stk.empty()) {
            auto &temp = stk.top();
            curr = temp.first;
            int &i = temp.second;
            if (i == 0) {
                if (curr->left) stk.push({curr->left, 0});
                i++;
            } else if (i == 1) {
                if (curr->right) stk.push({curr->right, 0});
                i++;
            } else {
                res.push_back(curr->val);
                stk.pop();
            }
        }
        return res;
    }
};

// Iteration with a stack. Push every left child into stack until left=NULL. Then step back and check right child. When
// a node has no right child or right child has been visited, record the value and pop from stack. Time complexity is
// O(n), space complexity is O(n).
class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *curr = root, *temp = NULL, *last = NULL;
        while (curr || !stk.empty()) {
            if (curr) {
                stk.push(curr);
                curr = curr->left;
            } else {
                temp = stk.top();
                if (temp->right && temp->right != last) curr = temp->right;
                else {
                    res.push_back(temp->val);
                    last = temp;
                    stk.pop();
                }
            }
        }
        return res;
    }
};