using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// recursion. Time complexity is O(n), space complexity is O(n).
class Solution {
private:
    int sumOfNode(TreeNode *root, int lastSum) {
        if (!root) return 0;
        int currSum = lastSum * 10 + root->val;
        if (!root->left && !root->right) return currSum;
        else return sumOfNode(root->left, currSum) + sumOfNode(root->right, currSum);
    }

public:
    int sumNumbers(TreeNode *root) {
        return sumOfNode(root, 0);
    }
};