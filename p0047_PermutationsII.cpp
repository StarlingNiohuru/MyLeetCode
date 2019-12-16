#include <vector>
#include <algorithm>

using namespace std;

// Backtracking. Sort the list first and use visited[i] and nums[i] == nums[i - 1] to cut off duplicate trees.
class Solution {
private:
    void backtrack(vector<int> &nums, vector<vector<int>> &res, vector<int> &curr, vector<bool> &visited) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
            else {
                curr.push_back(nums[i]);
                visited[i] = true;
                backtrack(nums, res, curr, visited);
                curr.pop_back();
                visited[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<bool> visited(nums.size(), false);
        vector<vector<int>> res;
        backtrack(nums, res, curr, visited);
        return res;
    }
};