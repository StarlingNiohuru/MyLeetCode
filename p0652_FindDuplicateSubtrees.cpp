#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// related to p0606. Serialize the subtree of every node and use a hash map<string,int> with serial string as key to
// count frequency. If the value=2, push the node into the answer list.
// Time complexity is O(n^2). Space complexity is O(n^2).
class Solution {
private:
    string serialize(TreeNode *node, unordered_map<string, int> &serialMap, vector<TreeNode *> &res) {
        if (!node) return "";
        string serial = "(" + serialize(node->left, serialMap, res) + to_string(node->val) +
                        serialize(node->right, serialMap, res) + ")";
        serialMap[serial]++;
        if (serialMap[serial] == 2) res.push_back(node);
        return serial;
    }

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        unordered_map<string, int> serialMap;
        vector<TreeNode *> res;
        serialize(root, serialMap, res);
        return res;
    }
};