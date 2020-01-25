#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// dfs backtracking. We should sort the list first and use a set to eliminate duplicate on every recursive layer.
// Time complexity is O(2^n).
class Solution {
private:
    void backtrack(vector<int> &nums, vector<vector<int>> &res, vector<int> &curr, int i) {
        res.push_back(curr);
        unordered_set<int> s;
        for (int j = i; j < nums.size(); j++)
            if (!s.count(nums[j])) {
                curr.push_back(nums[j]);
                backtrack(nums, res, curr, j + 1);
                curr.pop_back();
                s.insert(nums[j]);
            }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(nums, res, curr, 0);
        return res;
    }
};