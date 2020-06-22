#include <vector>

using namespace std;

// accCount[num] is first to count the frequency of each num. Then it's used to store accumulative count (accCount[num]
// represents the total number of elements <=num). At last traverse nums again and get the result by accCount[num-1].
// Time complexity is O(n) and Space complexity is O(1).
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
        vector<int> res;
        vector<int> accCount(101, 0);
        for (int num:nums) accCount[num]++;
        for (int i = 1; i <= 100; i++) accCount[i] += accCount[i - 1];
        for (int num:nums) res.push_back((num > 0) ? accCount[num - 1] : 0);
        return res;
    }
};