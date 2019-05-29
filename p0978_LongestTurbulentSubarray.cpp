class Solution {
public:
    int maxTurbulenceSize(vector<int> &A) {
        int left = 0, res = 1;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] == A[i - 1]) left = i;
            else if (i < 2 || (A[i] > A[i - 1] && A[i - 1] < A[i - 2]) ||
                     (A[i] < A[i - 1] && A[i - 1] > A[i - 2]))
                res = max(res, i - left + 1);
            else left = i - 1;
        }
        return res;
    }
};