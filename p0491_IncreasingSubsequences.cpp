#include <vector>
#include <unordered_set>

using namespace std;

// dfs backtracking. Because the answer should be an increasing subsequence, we can use a set to eliminate duplicate
// at every stage. Time complexity is O(2^n).
class Solution {
private:
    void backtrack(vector<vector<int>> &res, vector<int> &seq, vector<int> &nums, int pos) {
        if (seq.size() > 1) res.push_back(seq);
        unordered_set<int> s;
        for (int i = pos; i < nums.size(); i++) {
            if ((seq.empty() || seq.back() <= nums[i]) && !s.count(nums[i])) {
                seq.push_back(nums[i]);
                backtrack(res, seq, nums, i + 1);
                seq.pop_back();
                s.insert(nums[i]);
            }
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> seq;
        backtrack(res, seq, nums, 0);
        return res;
    }
};