#include <vector>

using namespace std;

// dp iteration. dp[i][j] represents the max mutual prefix before A[i] and B[j]. When A[i] = B[j],
// dp[i + 1][j + 1] = dp[i][j] + 1; When A[i] != B[j], dp[i + 1][j + 1] = 0. The max dp[i][j] is the answer.
// Time complexity is O(M * N) (M = A.size(), N = B.size())
class Solution {
public:
    int findLength(vector<int> &A, vector<int> &B) {
        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
        int res = INT32_MIN;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                if (A[i] == B[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
                else dp[i + 1][j + 1] = 0;
                res = max(res, dp[i + 1][j + 1]);
            }
        }
        return res;
    }
};