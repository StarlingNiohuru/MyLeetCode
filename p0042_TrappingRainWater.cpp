#include <iostream>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
//        use two pointers, a little slow, perhaps needs improve
        int i = 0, j = height.size() - 1, res = 0, iMax = 0, jMax = 0;
        while (i < j) {
            if (height[i] < height[j]) {
                height[i] < iMax ? (res += iMax - height[i]) : (iMax = height[i]);
                i++;
            } else {
                height[j] < jMax ? (res += jMax - height[j]) : (jMax = height[j]);
                j--;
            }
        }
        return res;
    }
};