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
            if (map.find(sum - k) != map.end()) { res += map[sum - k]; }
            map[sum] += 1;
        }
        return res;
    }
};
