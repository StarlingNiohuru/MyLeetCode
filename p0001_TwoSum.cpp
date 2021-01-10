#include <vector>
#include <iostream>
#include <unordered_map>
#include <iterator>

using namespace std;

// Hash table. When nums[i]=a is not in hashmap, insert map[a]=i.If we find nums[j]=b and map[target-b] in map, return {i,j}.
// Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> res(2);
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) == map.end()) {
                map[nums[i]] = i;
            } else {
                res[0] = map[target - nums[i]];
                res[1] = i;
                return res;
            }
        }
        return {};
    }
};
