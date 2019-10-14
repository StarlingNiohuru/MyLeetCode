#include <vector>

using namespace std;

// backtracking recursion. same as p39.
// There is a better way to reduce calculation in each step: ((2 * i + need - 1) * need / 2 <= target
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> combination;
        backtrack(res, k, combination, n, 1);
        return res;
    }

private:
    void backtrack(vector<vector<int>> &res, int need, vector<int> &combination, int target, int start) {
        if (need == 0) { if (target == 0) res.push_back(combination); else return; }
        else {
            for (int i = start; i < 10 && ((2 * i + need - 1) * need / 2 <= target); i++) {
                combination.push_back(i);
                backtrack(res, need - 1, combination, target - i, i + 1);
                combination.pop_back();
            }
        }
    }
};