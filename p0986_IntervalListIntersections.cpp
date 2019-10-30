#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B) {
        vector<vector<int>> res;
        int i = 0, j = 0, tmpStart, tmpEnd;
        while (i < A.size() && j < B.size()) {
            tmpStart = max(A[i][0], B[j][0]);
            tmpEnd = min(A[i][1], B[j][1]);
            if (tmpStart <= tmpEnd) res.push_back({tmpStart, tmpEnd});
            if (A[i][1] < B[j][1]) i++;
            else j++;
        }
        return res;
    }
};