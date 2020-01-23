#include <vector>

using namespace std;

// dp iteration. This problem is related to p0300. length[i] represents the length of the longest increasing subsequence
// in nums[0,i] and it must include nums[i]. count[i] represents the corresponding total numbers of LIS. We have:
// length[i] = max(list[length[j]]) + 1 where 0<=j<i and nums[j]<nums[i].
// count[i] = sum(list[count[j]]) where 0<=j<i and nums[j]<nums[i] and length[i]=length[j]+1.
// At last the sum of all the count[k] where k is max of length[i] is the answer. Time complexity is O(n^2). Space
// complexity is O(n).
class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) {
        int res = 0, maxLen = 0, n = nums.size();
        vector<int> length(n, 1), count(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j]) {
                    if (length[i] <= length[j]) {
                        length[i] = length[j] + 1;
                        count[i] = count[j];
                    } else if (length[i] == length[j] + 1) count[i] += count[j];
                }
            maxLen = max(maxLen, length[i]);
        }
        for (int i = 0; i < n; i++)
            if (length[i] == maxLen) res += count[i];
        return res;
    }
};
