#include <vector>
#include <queue>

using namespace std;

// related to p207. BFS of graph. Every step find all the leaf nodes(degree==1) and delete them, until the number of
// left nodes<=2. The answer are the left nodes. Time complexity is O(n) and space complexity is O(n).
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adj(n, vector<int>());
        vector<int> degree(n, 0);
        for (vector<int> &p:edges) {
            adj[p[1]].push_back(p[0]);
            adj[p[0]].push_back(p[1]);
            degree[p[0]]++;
            degree[p[1]]++;
        }
        queue<int> q;
        if (n == 1) q.push(0);
        for (int i = 0; i < n; i++)
            if (degree[i] == 1) q.push(i);
        while (n > 2) {
            int levelSize = q.size();
            while (levelSize > 0) {
                int curr = q.front();
                q.pop();
                n--;
                levelSize--;
                for (int neighbor:adj[curr])
                    if (--degree[neighbor] == 1) q.push(neighbor);
            }
        }
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};