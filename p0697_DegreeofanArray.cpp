#include <unordered_map>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int> &nums) {
//        use 2 hashmaps, for every element, left to record begin index, count to save frequency
        int res = 0, degree = 0;
        unordered_map<int, int> left, count;
        for (int i = 0; i < nums.size(); i++) {
            if (left.count(nums[i]) == 0) left[nums[i]] = i;
            if (++count[nums[i]] > degree) {
                degree = count[nums[i]];
                res = i - left[nums[i]] + 1;
            } else if (count[nums[i]] == degree)
                res = min(res, i - left[nums[i]] + 1);
        }
        return res;
    }
};