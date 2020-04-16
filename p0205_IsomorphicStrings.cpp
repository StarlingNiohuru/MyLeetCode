#include <vector>

using namespace std;

// Use 2 hash tables(vectors are OK) to record the last index of every character. If the indexes of s[i] and t[i] are
// different, that means they are not isomorphic. Time complexity is O(n). Space complexity is O(n).
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> map1(256, -1), map2(256, -1);
        for (int i = 0; i < s.size(); i++)
            if (map1[s[i]] == map2[t[i]]) {
                map1[s[i]] = i;
                map2[t[i]] = i;
            } else return false;
        return true;
    }
};

