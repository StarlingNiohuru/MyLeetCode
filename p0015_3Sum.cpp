#include <vector>
#include <iostream>
#include <unordered_set>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        unordered_set<int> set;
        for (auto it1 = nums.begin(); it1 != nums.end(); ++it1) {
            for (auto it2 = it1 + 1; *it2 <= 0 - *it1; ++it2) {
                auto got = set.find(0 - *it1 - *it2);
                if (got == set.end()) {
                    set.insert(*it2);
                } else {
                    res.push_back({*it1, *it2, 0 - *it1 - *it2});
                    cout << *it1 << "," << *it2 << "," << 0 - *it1 - *it2 << endl;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int target = 9;
    vector<vector<int>> result = solution.threeSum(nums);
//    cout << result[0] << "," << result[1] << endl;
    return 0;
}