#include <vector>
#include <queue>

using namespace std;

// BFS Topological Sort. similar to p207. Time complexity is O(n+m) and space complexity is O(n+m).
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<int> res;
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> inDegree(numCourses, 0);
        for (vector<int> &p:prerequisites) {
            adj[p[1]].push_back(p[0]);
            inDegree[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (inDegree[i] == 0) q.push(i);
        while (!q.empty()) {
            int curr = q.front();
            res.push_back(curr);
            q.pop();
            numCourses--;
            for (int n:adj[curr])
                if (--inDegree[n] == 0) q.push(n);
        }
        if (numCourses > 0) res.clear();
        return res;
    }
};