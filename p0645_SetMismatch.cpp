#include <vector>
#include <unordered_set>

using namespace std;

// Use a set to find the duplicate num. Then calculate the missing num
class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        vector<int> res = {0, 0};
        int sum = 0, n = nums.size();
        unordered_set<int> numsSet;
        for (int num:nums) {
            if (numsSet.count(num)) res[0] = num;
            else numsSet.insert(num);
            sum += num;
        }
        res[1] = (n + 1) * n / 2 - sum + res[0];
        return res;
    }
};