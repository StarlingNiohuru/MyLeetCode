#include <vector>
#include <unordered_set>

using namespace std;

// hash table. Time complexity is O(n) and space complexity is O(n).
class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> s;
        for (int num:nums)
            if (s.count(num)) return true;
            else s.insert(num);
        return false;
    }
};