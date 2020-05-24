#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Use pre-order traversal recursive method to serialize a tree. Use recursive dfs to deserialize string.
// Either serialize() or deserialize()'s time complexity is O(n) and space complexity is O(n).
class Codec {
private:
    TreeNode *deserializeNode(istringstream &iss) {
        string val;
        iss >> val;
        if (val == "#") return NULL;
        auto *node = new TreeNode(stoi(val, nullptr));
        node->left = deserializeNode(iss);
        node->right = deserializeNode(iss);
        return node;
    }

public:
    string serialize(TreeNode *root) {
        if (root == nullptr) return "#";
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

    TreeNode *deserialize(string data) {
        istringstream iss(data);
        return deserializeNode(iss);
    }
};