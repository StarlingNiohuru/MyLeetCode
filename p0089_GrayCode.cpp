#include <vector>

using namespace std;

// dp iteration. grayCode(n) can be generated by grayCode(n-1) as this way: For example grayCode(2) is [00,01,11,10].
// We can generate grayCode(3) by 0 add [00,01,11,10] and 1 add [10,11,01,00]. Time complexity is O(2^n).
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1, 0);
        for (int i = 0; i < n; i++)
            for (int j = res.size() - 1; j >= 0; j--)
                res.push_back(res[j] | (1 << i));
        return res;
    }
};