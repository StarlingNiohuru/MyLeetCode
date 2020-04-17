#include <vector>
#include <queue>

using namespace std;

// This problem can be represented as a graph. The answer is whether the graph is a Directed Acyclic Graph(DAG).
// We solve the problem by a BFS version's Topological Sort: Use a adjacent list adj to record data of the graph
// and a vector to save in-degree of every node. Push all 0-in-degree nodes into the queue. Every step, pop the front
// element of the queue(numCourses--) and delete the node by deleting the all its edges to next nodes(--inDegree[nextNode]).
// If we find a next node having 0 in-degree after deleting, push it into the queue. At last when queue is empty, if
// there is no nodes left (numCourses==0), that means the graph is a DAG. Time complexity is O(n+m). Space complexity
// is O(n+m) where n is the number of nodes and m is the ones of edges.
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
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
            q.pop();
            numCourses--;
            for (int n:adj[curr])
                if (--inDegree[n] == 0) q.push(n);
        }
        return numCourses == 0;
    }
};