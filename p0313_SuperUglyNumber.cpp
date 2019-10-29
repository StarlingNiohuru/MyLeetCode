#include <vector>
#include <utility>
#include <queue>

using namespace std;

// This problem is similar to p0264. It needs a critical step to find the min of prime*dp[pointer(prime)]
// Use a heap to save {prime*dp[pointer(prime)], pointer(prime)}. Time complexity should be O(log(k)*n). But a little slow
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        vector<int> dp(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dp[0] = 1;
        for (int x:primes)
            pq.push({x, 0});
        int last = 1;
        for (int i = 1; i < n; i++) {
            auto minCandidate = pq.top();
            if (minCandidate.first == last)i--;
            dp[i] = minCandidate.first;
            pq.pop();
            pq.push({(dp[i] / dp[minCandidate.second]) * dp[minCandidate.second + 1], minCandidate.second + 1});
            last = dp[i];
        }
        return dp[n - 1];
    }
};