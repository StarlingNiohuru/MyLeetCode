#include <vector>

using namespace std;

// Greedy. start from index 0. curr is used to record current gas of the car. if curr is less<0, reset it to 0 and set
// i+1 as the new start point. total is to record the whole difference between gas and cost. If total<0 means we can't
// finish the circle so answer is -1. If total>=0, the last start point that curr>=0 is the answer (It can be proved
// that the car has enough gas to finish the rest of the route). Time complexity is O(n), space complexity is O(1).
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int curr = 0, total = 0, res = 0;
        for (int i = 0; i < gas.size(); i++) {
            curr += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (curr < 0) {
                curr = 0;
                res = i + 1;
            }
        }
        if (total < 0) res = -1;
        return res;
    }
};