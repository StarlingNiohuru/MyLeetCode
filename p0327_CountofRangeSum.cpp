#include <vector>

using namespace std;

// related to p0315 and p0493. First we need an accumulative list sums[i+1] = nums[i+1] - num[i]. We will find this problem
// is equal to finding all the pairs(i,j) satisfying lower<=sums[i]-sums[j]<=upper, which is similar to reverse pairs
// problem by merge sort. Time complexity is O(n*log(n)) and Space complexity is O(n).
class Solution {
private:
    void mergeSort(int &res, vector<long> &nums, vector<long> &temp, int l, int r, int lower, int upper) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(res, nums, temp, l, mid, lower, upper);
        mergeSort(res, nums, temp, mid + 1, r, lower, upper);
        int i = l, j, j1 = mid + 1, j2 = mid + 1, k;
        while (i <= mid) {
            while (j1 <= r && nums[j1] - nums[i] < lower) j1++;
            while (j2 <= r && nums[j2] - nums[i] <= upper) j2++;
            res += (j2 - j1);
            i++;
        }
        i = l, j = mid + 1, k = l;
        while (i <= mid || j <= r)
            if (j > r || (i <= mid && nums[i] <= nums[j])) temp[k++] = nums[i++];
            else temp[k++] = nums[j++];
        for (int x = l; x <= r; x++) nums[x] = temp[x];
    }

public:
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        int n = nums.size(), res = 0;
        vector<long> sums(n + 1, 0), temp(n + 1);
        for (int i = 0; i < n; i++) sums[i + 1] = sums[i] + nums[i];
        mergeSort(res, sums, temp, 0, n, lower, upper);
        return res;
    }
};