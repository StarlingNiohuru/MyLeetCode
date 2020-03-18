#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// BFS iteration. Use a hash map to record visited nodes. Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    Node *cloneGraph(Node *node) {
        if (!node) return NULL;
        unordered_map<Node *, Node *> visited;
        queue<Node *> q;
        q.push(node);
        Node *res = new Node(node->val);
        visited[node] = res;
        while (!q.empty()) {
            Node *curr = q.front();
            q.pop();
            for (auto neighbor:curr->neighbors) {
                if (!visited.count(neighbor)) {
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                visited[curr]->neighbors.push_back(visited[neighbor]);
            }
        }
        return res;
    }
};