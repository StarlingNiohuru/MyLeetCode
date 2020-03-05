#include <vector>

using namespace std;

// greedy. Time complexity is O(n). Space complexity is O(1).
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int minPrice = INT32_MAX, res = 0;
        for (int p:prices) {
            minPrice = min(minPrice, p);
            res = max(res, p - minPrice);
        }
        return res;
    }
};

