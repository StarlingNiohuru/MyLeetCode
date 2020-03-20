#include <vector>

using namespace std;

// Use 2 vectors to record possible candies. First every element has at least 1 candy. Then to vector1, we traverse
// from left to right. If ratings[i-1] < ratings[i], let candiesLeft[i] = candiesLeft[i - 1] + 1. To vector2 we traverse
// from right to left and let candiesRight[i] = candiesRight[i + 1] + 1 when ratings[i] > ratings[i + 1]. Next we need
// to calculate max(vector1[i],vector2[i]) which is the min candies of every child. At last the final answer is the sum
// of the max list. Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size(), res = 0;
        vector<int> candiesLeft(n, 1), candiesRight(n, 1);
        for (int i = 1; i < n; i++)
            if (ratings[i - 1] < ratings[i]) candiesLeft[i] = candiesLeft[i - 1] + 1;
        for (int i = n - 2; i >= 0; i--)
            if (ratings[i] > ratings[i + 1]) candiesRight[i] = candiesRight[i + 1] + 1;
        for (int i = 0; i < n; i++)
            res += max(candiesLeft[i], candiesRight[i]);
        return res;
    }
};