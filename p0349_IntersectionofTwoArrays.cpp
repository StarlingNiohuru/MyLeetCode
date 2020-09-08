#include <vector>
#include <unordered_set>

using namespace std;

// hash set.Time complexity is O(n1+n2).Space complexity is O(min(n1,n2)).
class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> res;
        for (int num:nums2) {
            if (s.count(num)) {
                res.push_back(num);
                s.erase(num);
            }
        }
        return res;
    }
};