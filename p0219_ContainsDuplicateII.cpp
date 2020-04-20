#include <vector>
#include <unordered_set>

using namespace std;

//similar to p0217. Use hash table as a sliding window. Time complexity is O(n) and space complexity is O(n).
class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (s.count(nums[i])) return true;
            else s.insert(nums[i]);
            if (s.size() > k) s.erase(nums[i - k]);
        }
        return false;
    }
};