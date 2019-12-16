#include <vector>
#include <utility>

using namespace std;

// Backtracking. Swap the current num with every num behind to create all the permutations.
class Solution {
private:
    void backtrack(vector<int> &nums, vector<vector<int>> &res, int i) {
        if (i == nums.size()) res.push_back(nums);
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            backtrack(nums, res, i + 1);
            swap(nums[i], nums[j]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        backtrack(nums, res, 0);
        return res;
    }
};