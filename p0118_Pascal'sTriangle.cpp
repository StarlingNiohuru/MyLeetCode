#include <vector>

using namespace std;

// iteration. Time complexity is O(n^2), space complexity is O(n^2).
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        if (numRows > 0) res[0].push_back(1);
        for (int i = 1; i < numRows; i++) {
            res[i].push_back(1);
            for (int j = 1; j < res[i - 1].size(); j++)
                res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
            res[i].push_back(1);
        }
        return res;
    }
};