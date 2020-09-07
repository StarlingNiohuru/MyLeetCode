#include <vector>

using namespace std;

// 2 pointers.Time complexity is O(n).Space complexity is O(1).
class Solution {
public:
    void reverseString(vector<char> &s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
            swap(s[i], s[n - 1 - i]);
    }
};