#include <vector>
#include <algorithm>

using namespace std;

// Soft the list first. Then rearrange the list like this:
// [a(m), a(n-1), a(m-1), a(n-2), ..., a1, a(m+2), a0, a(m+1)] (m is the median, n is the length)
class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) nums[i] = tmp[(n - i - 1) / 2];
            else nums[i] = tmp[(2 * n - i - 1) / 2];
        }
    }
};