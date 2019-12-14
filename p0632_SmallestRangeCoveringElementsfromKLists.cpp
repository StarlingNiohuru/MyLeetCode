#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// Use a heap to record k elements with their list's label from every list. And use a hash table kMap[currList] for
// storing every list's current index. In each step,we record the max num and calculate the range's length with keeping
// the heap with k elements from each list and update kMap[currList] by +1, until current index > current list's length.
// Time complexity is O(n*k*log(k)) where n is the length of average list.
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>> &nums) {
        vector<int> res(2);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int maxInRange = INT32_MIN, minInRange, RangeLength = INT32_MAX, currList, currIndex;
        unordered_map<int, int> kMap;
        for (int i = 0; i < nums.size(); i++) {
            kMap[i] = 0;
            pq.push({nums[i][0], i});
            maxInRange = max(maxInRange, nums[i][0]);
        }
        while (true) {
            auto tmp = pq.top();
            minInRange = tmp.first, currList = tmp.second;
            if (maxInRange - minInRange < RangeLength) {
                res[0] = minInRange, res[1] = maxInRange;
                RangeLength = maxInRange - minInRange;
            }
            pq.pop();
            currIndex = ++kMap[currList];
            if (currIndex < nums[currList].size()) {
                pq.push({nums[currList][currIndex], currList});
                maxInRange = max(maxInRange, nums[currList][currIndex]);
            } else break;
        }
        return res;
    }
};