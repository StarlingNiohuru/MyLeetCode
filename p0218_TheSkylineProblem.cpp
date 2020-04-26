#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// First sort all the critical points (entering and leaving point of a building) by x axis, marking entering point with
// -height. Then traverse these points with a multiset inserting or erasing corresponding height. If the max height in
// the set is different from previous key point's height, push the new key point into the answer.
// Time complexity is O(n*log(n)). Space complexity is O(n).
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        vector<vector<int>> heights;
        for (auto building:buildings) {
            heights.push_back({building[0], -building[2]});
            heights.push_back({building[1], building[2]});
        }
        sort(heights.begin(), heights.end());
        vector<vector<int>> res;
        int pre = 0, curr;
        multiset<int> mSet;
        mSet.insert(0);
        for (auto height:heights) {
            if (height[1] < 0) mSet.insert(-height[1]);
            else mSet.erase(mSet.find(height[1]));
            curr = *mSet.rbegin();
            if (pre != curr) {
                res.push_back({height[0], curr});
                pre = curr;
            }
        }
        return res;
    }
};