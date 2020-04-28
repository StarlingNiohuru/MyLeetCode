#include <vector>
#include <map>

using namespace std;

// related to p0218 and p0715. First we can use an ordered map <x of key point, height> to represent the block below.
// When a square covering [a,b] drop down, we need to find the max height at [a,b) of the map and then replace this range
// with new height=max height + side length of square. At the same time, check and record the max height of all map.
// Time complexity is O(n*log(n)). Space complexity is O(n).
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>> &positions) {
        map<int, int> heightMap;
        heightMap[0] = 0;
        vector<int> res;
        int maxHeight = 0;
        for (auto &position:positions) {
            int len = position[1], a = position[0], b = a + len, height = 0, lastHeight = 0;
            auto ita = heightMap.lower_bound(a), itb = heightMap.lower_bound(b);
            if (ita != heightMap.begin() && heightMap.find(a) == heightMap.end()) ita--;
            for (auto it = ita; it != itb; it++) {
                height = max(height, it->second);
                lastHeight = it->second;
            }
            if (ita->first < a) ita++;
            heightMap.erase(ita, itb);
            heightMap[a] = height + len;
            if (itb == heightMap.end()) heightMap[b] = 0;
            else if (itb->first != b) heightMap[b] = lastHeight;
            maxHeight = max(maxHeight, height + len);
            res.push_back(maxHeight);
        }
        return res;
    }
};