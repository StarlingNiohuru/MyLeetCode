#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// dfs backtracking. Time complexity is O(n), space complexity is O(n).
class Solution {
private:
    void backtrack(string &res, TreeNode *root, string s) {
        if (!root) return;
        s += char('a' + root->val);
        if (!root->left && !root->right) {
            reverse(s.begin(), s.end());
            if (s < res) res = s;
            return;
        }
        backtrack(res, root->left, s);
        backtrack(res, root->right, s);
    };
public:
    string smallestFromLeaf(TreeNode *root) {
        string res = "{";
        backtrack(res, root, "");
        res = (res == "{") ? "" : res;
        return res;
    }
};