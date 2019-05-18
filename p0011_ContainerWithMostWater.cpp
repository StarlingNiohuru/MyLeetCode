#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
//        use two pointers from both side
        int i = 0, j = height.size() - 1, res = 0;
        while (i < j) {
            int h = min(height[i], height[j]);
            res = max(res, (j - i) * h);
            if (height[i] <= height[j]) i++;
            else j--;

        }
        return res;
    }
};