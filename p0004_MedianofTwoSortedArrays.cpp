#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m, n;
        m = nums1.size(), n = nums2.size();
        if (m > n) { return findMedianSortedArrays(nums2, nums1); }
        int i, j, imin, imax, leftmax, rightmin;
        imin = 0, imax = m;
        while (imin <= imax) {
            i = (imin + imax) / 2;
            j = (m + n + 1) / 2 - i;
            if (i < m && nums1[i] < nums2[j - 1]) { imin = i + 1; }
            else if (i > 0 && nums1[i - 1] > nums2[j]) { imax = i - 1; }
            else {
                if (i == 0) { leftmax = nums2[j - 1]; }
                else if (j == 0) { leftmax = nums1[i - 1]; }
                else { leftmax = max(nums1[i - 1], nums2[j - 1]); }
                if (i == m) { rightmin = nums2[j]; }
                else if (j == n) { rightmin = nums1[i]; }
                else { rightmin = min(nums1[i], nums2[j]); }
                if ((m + n) % 2 == 1) {
                    return leftmax;
                } else { return (leftmax + rightmin) / 2.0; }
            };
        }
    }
};
