#include <vector>

using namespace std;

// We use binary search to find the left boundary. When x - arr[mid] > arr[mid + k] - x, mid must be at the left of the
// point we search. Vice versa. Time complexity is O(log(n-k)).
class Solution {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        int lo = 0, hi = arr.size() - k, mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2; // avoid int overflow
            if (x - arr[mid] > arr[mid + k] - x) lo = mid + 1;
            else hi = mid;
        }
        vector<int> res(arr.begin() + lo, arr.begin() + lo + k);
        return res;
    }
};