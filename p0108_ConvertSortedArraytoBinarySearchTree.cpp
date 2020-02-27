#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// recursion. Because the tree must be balanced, we could choose the middle of the list every step.
// Notice that the answer is not unique. Time complexity is O(n), space complexity is O(n).
class Solution {
private:
    TreeNode *build(vector<int> &nums, int start, int stop) {
        if (start > stop) return NULL;
        int mid = (start + stop) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = build(nums, start, mid - 1);
        root->right = build(nums, mid + 1, stop);
        return root;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return build(nums, 0, nums.size() - 1);
    }
};