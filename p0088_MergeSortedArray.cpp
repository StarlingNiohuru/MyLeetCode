#include <vector>

using namespace std;

// fill nums1 from back to front
class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int point = m + n - 1, point1 = m - 1, point2 = n - 1;
        while (point1 >= 0 && point2 >= 0) {
            if (nums1[point1] > nums2[point2]) {
                nums1[point] = nums1[point1];
                point1--;
            } else {
                nums1[point] = nums2[point2];
                point2--;
            }
            point--;
        }
        for (; point2 >= 0; point--, point2--) nums1[point] = nums2[point2];
    }
};