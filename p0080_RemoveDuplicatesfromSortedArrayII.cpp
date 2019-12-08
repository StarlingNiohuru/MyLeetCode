#include <vector>

using namespace std;

// 2 pointers. similar to p0026
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int i = 0;
        for (int num:nums) {
            if (i < 2 || num > nums[i - 2])
                nums[i++] = num;
        }
        return i;
    }
};