#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// related to p0096. We divide the n-th BST from the i-th node and generate the left and right tree recursively where i
// is from 1 to n. Time complexity is O(4^n/sqrt(n)). Space complexity is O(4^n/sqrt(n)).
class Solution {
private:
    vector<TreeNode *> generateTree(int start, int stop) {
        vector<TreeNode *> res;
        if (start > stop) res.push_back(NULL);
        else {
            for (int i = start; i <= stop; i++) {
                vector<TreeNode *> l = generateTree(start, i - 1);
                vector<TreeNode *> r = generateTree(i + 1, stop);
                for (auto &j : l)
                    for (auto &k : r) {
                        TreeNode *root = new TreeNode(i);
                        root->left = j;
                        root->right = k;
                        res.push_back(root);
                    }
            }
        }
        return res;
    }

public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) return vector<TreeNode *>();
        return generateTree(1, n);
    }
};
