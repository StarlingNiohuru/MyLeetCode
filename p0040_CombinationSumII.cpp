#include <vector>
#include <algorithm>

using namespace std;

// backtracking recursion. same as p39
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        backtrack(res, candidates, combination, target, 0);
        return res;
    }

private:
    void backtrack(vector<vector<int>> &res, vector<int> &candidates, vector<int> &combination, int target, int start) {
        if (target == 0) res.push_back(combination);
        else {
            for (int i = start; i < candidates.size() && candidates[i] <= target; i++) {
                if (i == start || candidates[i] != candidates[i - 1]) {
                    combination.push_back(candidates[i]);
                    backtrack(res, candidates, combination, target - candidates[i], i + 1);
                    combination.pop_back();
                }
            }
        }
    }
};