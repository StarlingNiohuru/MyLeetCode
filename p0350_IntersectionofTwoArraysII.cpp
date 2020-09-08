#include <vector>
#include <unordered_map>

using namespace std;

// similar to p0349. Hash table.Time complexity is O(n1+n2).Space complexity is O(min(n1,n2)).
class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> m;
        vector<int> res;
        for (int num:nums1) m[num]++;
        for (int num:nums2)
            if (m.count(num) && m[num] > 0) {
                res.push_back(num);
                m[num]--;
            }
        return res;
    }
};