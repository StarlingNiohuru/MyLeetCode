#include <vector>

using namespace std;

// dfs backtracking. Time complexity is O(2^n).
class Solution {
private:
    void backtrack(vector<int> &nums, vector<vector<int>> &res, vector<int> &curr, int i) {
        res.push_back(curr);
        for (int j = i; j < nums.size(); j++) {
            curr.push_back(nums[j]);
            backtrack(nums, res, curr, j + 1);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(nums, res, curr, 0);
        return res;
    }
};