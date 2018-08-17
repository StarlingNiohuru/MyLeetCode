#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int res = 0;
        int sum = 0;
        unordered_map<int, int> map;
        ++map[0];
        for (auto n:nums) {
            sum += n;
            res += map[sum - k];
            ++map[sum];
        }
        return res;
    }
};
