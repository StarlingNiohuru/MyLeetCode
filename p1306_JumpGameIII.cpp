#include <vector>
#include <queue>

using namespace std;

// bfs. Use a queue to add every new index with a vector or hash table to record visited index until arr[i]=0.
// Time complexity is O(n).
class Solution {
public:
    bool canReach(vector<int> &arr, int start) {
        queue<int> q;
        vector<bool> visited(arr.size(), false);
        q.push(start);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (arr[i] == 0) return true;
            if (visited[i]) continue;
            else visited[i] = true;
            if (i + arr[i] < arr.size()) q.push(i + arr[i]);
            if (i - arr[i] >= 0) q.push(i - arr[i]);
        }
        return false;
    }
};