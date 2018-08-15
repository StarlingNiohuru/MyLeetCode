#include <vector>
#include <iostream>
#include <unordered_map>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res(2);
        unordered_map<int, int> map;
        for (auto it = numbers.begin(); it != numbers.end(); ++it) {
            int i = it - numbers.begin();
            auto got = map.find(target - *it);
            if (got == map.end()) {
                map.insert({*it, i});
            } else {
                res[0] = map[target - *it] + 1;
                res[1] = i + 1;
                return res;
            }
        }
        return {};
    }
};


