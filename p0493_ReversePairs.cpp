#include <vector>

using namespace std;

// merge sort. Before each sub-merging, we can count numbers satisfying condition nums[i]>nums[j]*2 by 2 pointers i, j.
// Time complexity is O(n*log(n)) and Space complexity is O(n).
class Solution {
private:
    void mergeSort(int &res, vector<int> &nums, vector<int> &temp, int l, int r) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(res, nums, temp, l, mid);
        mergeSort(res, nums, temp, mid + 1, r);
        int i = l, j = mid + 1, k;
        while (i <= mid) {
            while (j <= r && nums[i] > nums[j] * 2LL) j++;
            res += (j - (mid + 1));
            i++;
        }
        i = l, j = mid + 1, k = l;
        while (i <= mid || j <= r)
            if (j > r || (i <= mid && nums[i] <= nums[j])) temp[k++] = nums[i++];
            else temp[k++] = nums[j++];
        for (int x = l; x <= r; x++) nums[x] = temp[x];
    }

public:
    int reversePairs(vector<int> &nums) {
        int n = nums.size(), res = 0;
        if (n > 0) {
            vector<int> temp(n);
            mergeSort(res, nums, temp, 0, n - 1);
        }
        return res;
    }
};