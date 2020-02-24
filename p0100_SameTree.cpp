#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// iteration with a queue. Every step pop pair<cp,cq> from front. If cp.left->val==cq.left->val, push the new pair into
// queue. Same as the cp.right and cq.right. Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p || !q) return p == q;
        else if (p->val != q->val) return false;
        queue<pair<TreeNode *, TreeNode *>> que;
        que.push({p, q});
        while (!que.empty()) {
            auto curr = que.front();
            que.pop();
            TreeNode *cp = curr.first, *cq = curr.second;
            if (cp->left && cq->left) {
                if (cp->left->val == cq->left->val)
                    que.push({cp->left, cq->left});
                else return false;
            } else if (cp->left || cq->left) return false;
            if (cp->right && cq->right) {
                if (cp->right->val == cq->right->val)
                    que.push({cp->right, cq->right});
                else return false;
            } else if (cp->right || cq->right) return false;

        }
        return true;
    }
};

// recursion. Time complexity is O(n), space complexity is O(n).
class Solution2 {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) return true;
        else if (!p || !q) return false;
        else return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};