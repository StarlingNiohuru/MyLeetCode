#include <vector>
#include <unordered_map>

using namespace std;

// related to p0219. Keep a sliding window of length k. Each step given a new element x, we need to check whether there
// is an element y which satisfying x-y<=t. The best way is using buckets (like [0,t],[t+1,2t]...) with hash table, which
// can make the search finished in O(1) time. Time complexity is O(n) and space complexity is O(n).
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        if (t < 0) return false;
        unordered_map<long, long> bucket;
        for (int i = 0; i < nums.size(); i++) {
            long bValue = long(nums[i]) - INT32_MIN;
            long bKey = bValue / (long(t) + 1);
            if (bucket.count(bKey)) return true;
            if (bucket.count(bKey - 1) && bValue - bucket[bKey - 1] <= t) return true;
            if (bucket.count(bKey + 1) && bucket[bKey + 1] - bValue <= t) return true;
            bucket[bKey] = bValue;
            if (i >= k) bucket.erase((long(nums[i - k]) - INT32_MIN) / (long(t) + 1));
        }
        return false;
    }
};