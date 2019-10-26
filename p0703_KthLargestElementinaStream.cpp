#include <queue>

using namespace std;

// same as p0215
class KthLargest {
    priority_queue<int, vector<int>, greater<>> pq;
    int size;
public:
    KthLargest(int k, vector<int> &nums) {
        size = k;
        for (int x:nums) {
            pq.push(x);
            if (pq.size() > size)pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > size)pq.pop();
        return pq.top();
    }
};