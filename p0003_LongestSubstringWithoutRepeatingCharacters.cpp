#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res, i, start;
        res = 0, start = 0;
        unordered_map<char, int> map;
        for (i = 0; i < s.size(); i++) {
            auto got = map.find(s[i]);
            if (got == map.end()) {
                map.insert({s[i], i});
            } else {
                if (map[s[i]] >= start) { start = map[s[i]] + 1; }
                map[s[i]] = i;
            }
            res = max(res, i - start + 1);
        }
        return res;
    };
};
