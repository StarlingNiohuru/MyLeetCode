#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int res = *nums.begin() + *(nums.begin() + 1) + *(nums.end() - 1);
        for (auto it0 = nums.begin(); it0 != nums.end(); ++it0) {
            if (it0 > nums.begin() && *it0 == *(it0 - 1)) { continue; }
            int twoSum = target - *it0;
            auto itf = it0 + 1, ite = nums.end() - 1;
            while (itf < ite) {
                if (abs(*it0 + *itf + *ite - target) < abs(res - target)) { res = *it0 + *itf + *ite; }
                if (*itf + *ite < twoSum || (itf > it0 + 1 && *itf == *(itf - 1))) { ++itf; }
                else if (*itf + *ite > twoSum || (ite < nums.end() - 1 && *ite == *(ite + 1))) { --ite; }
                else { return target; }
            }
        }
        return res;
    }
};
