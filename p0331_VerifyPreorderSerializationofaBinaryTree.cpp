#include <sstream>

using namespace std;

// The variable edges represents the number of the tree's edges. Every node including number or '#' consumes 1 edge and
// every non-empty nodes create 2 edges.A valid preorder string must have final edges==0 and edges are never <0.
// Time complexity is O(n). Space complexity is O(1).
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int edges = 1;
        string s;
        stringstream ss;
        ss << preorder;
        while (getline(ss, s, ',')) {
            edges--;
            if (edges < 0) return false;
            if (s[0] != '#') edges += 2;
        }
        return edges == 0;
    }
};