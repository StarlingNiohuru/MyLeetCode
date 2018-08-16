#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        if (nums.size() < 4) { return {}; }
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (auto it0 = nums.begin(); *it0 <= target / 4 + 1; ++it0) {
            if (it0 > nums.begin() && *it0 == *(it0 - 1)) { continue; }
            for (auto it1 = nums.end() - 1; *it1 >= target / 4 - 1; --it1) {
                if (it1 < nums.end() - 1 && *it1 == *(it1 + 1)) { continue; }
                int twoSum = target - *it0 - *it1;
                auto itf = it0 + 1, ite = it1 - 1;
                while (itf < ite) {
                    if (*itf + *ite < twoSum || (itf > it0 + 1 && *itf == *(itf - 1))) { ++itf; }
                    else if (*itf + *ite > twoSum || (ite < it1 - 1 && *ite == *(ite + 1))) { --ite; }
                    else {
                        res.push_back({*it0, *itf, *ite, *it1});
                        ++itf;
                        --ite;
                    }
                }
            }
        }
        return res;
    }
};

