#include <vector>
#include <iostream>
#include <unordered_map>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> res(2);
        unordered_map<int, int> map;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            int i = it - nums.begin();
            auto got = map.find(target - *it);
            if (got == map.end()) {
                map.insert({*it, i});
            } else {
                res[0] = map[target - *it];
                res[1] = i;
                return res;
            }
        }
        return {};
    }
};
