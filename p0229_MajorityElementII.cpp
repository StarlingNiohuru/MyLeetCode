#include <vector>

using namespace std;

// related to p0169 v2. Use 2 candidates. At last we need to check whether the counts of 2 candidates > n/3.
// Time complexity is O(n). Space complexity is O(1).
class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        int candidate1 = 0, candidate2 = 1, count1 = 0, count2 = 0;
        for (int num:nums)
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
            else if (count1 == 0) {
                candidate1 = num;
                count1++;
            } else if (count2 == 0) {
                candidate2 = num;
                count2++;
            } else {
                count1--;
                count2--;
            }
        count1 = 0, count2 = 0;
        for (int num:nums)
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        vector<int> res;
        if (count1 > nums.size() / 3) res.push_back(candidate1);
        if (count2 > nums.size() / 3) res.push_back(candidate2);
        return res;
    }
};