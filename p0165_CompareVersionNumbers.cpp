#include <sstream>

using namespace std;

//Time complexity is O(m+n). Space complexity is O(1).
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1, v2;
        char c;
        istringstream ss1(version1), ss2(version2);
        while (bool(ss1 >> v1) + bool(ss2 >> v2)) {
            if (v1 > v2) return 1;
            if (v1 < v2) return -1;
            v1 = 0, v2 = 0;
            ss1 >> c, ss2 >> c;
        }
        return 0;
    }
};