#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Backtracking. similar to p0047.
class Solution {
private:
    bool isPerfectSquare(int n) {
        int t = sqrt(n);
        return t * t == n;
    }

private:
    void backtrack(vector<int> &A, int &res, vector<int> &curr, vector<bool> &visited) {
        if (curr.size() == A.size()) {
            res++;
            return;
        }
        for (int i = 0; i < A.size(); i++) {
            if (visited[i]) continue;
            if (i > 0 && A[i] == A[i - 1] && !visited[i - 1]) continue;
            if (!curr.empty() && !isPerfectSquare(curr.back() + A[i])) continue;
            else {
                curr.push_back(A[i]);
                visited[i] = true;
                backtrack(A, res, curr, visited);
                curr.pop_back();
                visited[i] = false;
            }
        }
    }

public:
    int numSquarefulPerms(vector<int> &A) {
        sort(A.begin(), A.end());
        vector<int> curr;
        vector<bool> visited(A.size(), false);
        int res = 0;
        backtrack(A, res, curr, visited);
        return res;
    }
};