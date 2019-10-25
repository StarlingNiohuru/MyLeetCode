#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// Use a heap. A little slow
class Solution {
public:
    int thirdMax(vector<int> &nums) {
        priority_queue<int, vector<int>, greater<>> pq;
        unordered_set<int> s;
        for (int x:nums) {
            if (!s.count(x)) {
                pq.push(x);
                s.insert(x);
            }
            if (pq.size() > 3)pq.pop();
        }
        if (pq.size() == 3)
            return pq.top();
        else {
            int res;
            while (!pq.empty()) {
                res = pq.top();
                pq.pop();
            }
            return res;
        }
    }
};