#include <vector>

using namespace std;

// similar to p0118. iteration. Time complexity is O(n^2), space complexity is O(n).
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        for (int i = 2; i <= rowIndex; i++) {
            for (int j = i - 1; j > 0; j--)
                res[j] += res[j - 1];
        }
        return res;
    }
};