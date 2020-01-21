#include <vector>
#include <algorithm>

using namespace std;

// dp and binary search. tail[i] is used for storing an increasing list could appear in nums[0,i]. Traverse nums.
// If nums[i]> tail[-1], add nums[i] to the tail's end. If nums[i]< tail[-1], find the min tail's element which greater
// than nums[i] and replace it.(We need binary search to find it.) Sometimes tail is not a real increasing sequence
// of question demand, but the length always meet the requirement. Time complexity is O(n*log(n)). Space complexity is
// O(n).
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> tail;
        for (int num:nums) {
            if (tail.empty() || num > tail.back()) tail.push_back(num);
            else {
                auto it = lower_bound(tail.begin(), tail.end(), num); //binary search, find the min element>=num
                *it = num;
            }
        }
        return tail.size();
    }
};