#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int res = 0;
        int sum = 0;
        unordered_map<int, int> map = {{0, 1}};
        for (auto n:nums) {
            sum += n;
            map[sum] += 1;
            if (map.find(sum - k) != map.end()) { res += map[sum - k]; }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 4, 7, 2, -3, 1, 4, 2};
    int target = 7;
    int result = solution.subarraySum(nums, target);
    cout << result << endl;
    return 0;
}