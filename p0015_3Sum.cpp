#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        if (nums.empty()) { return {}; }
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (auto it0 = nums.begin(); *it0 <= 0; ++it0) {
            if (it0 > nums.begin() && *it0 == *(it0 - 1)) { continue; }
            int target = 0 - *it0;
            auto itf = it0 + 1, ite = nums.end() - 1;
            while (itf < ite) {
                if (*itf + *ite < target || (itf > it0 + 1 && *itf == *(itf - 1))) { ++itf; }
                else if (*itf + *ite > target || (ite < nums.end() - 1 && *ite == *(ite + 1))) { --ite; }
                else {
                    res.push_back({*it0, *itf, *ite});
                    ++itf;
                    --ite;
                }
            }
        }
        return res;
    }
};
