#include <vector>
#include <utility>

using namespace std;

// We can begin from 0 (start) and let the i-th value jump to (i + k) % n position one-by-one until i=start again.
// Notice that usually we haven't exchanged all the numbers in list so we need to let start=start+1 and repeat the
// process above until all the numbers have been exchanged. Time complexity is O(n).
class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int n = nums.size(), count = 0, curr, pre, cons;
        for (int start = 0; count < n; start++) {
            curr = start;
            pre = nums[start];
            do {
                cons = (curr + k) % n;
                swap(nums[cons], pre);
                curr = cons;
                count++;
            } while (curr != start);
        }
    }
};