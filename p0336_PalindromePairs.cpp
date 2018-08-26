#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string> &words) {
        unordered_map<string, int> map;
        vector<vector<int>> res;
        int i, j;
        string key, left, right;
        for (i = 0; i < words.size(); i++) {
            key = words[i];
            reverse(key.begin(), key.end());
            map[key] = i;
        }
        if (map.find("") != map.end()) {
            for (i = 0; i < words.size(); i++) {
                if (i != map[""] && isPalindrome(words[i])) { res.push_back({map[""], i}); }
            }
        }
        for (i = 0; i < words.size(); i++) {
            for (j = 0; j < words[i].size(); j++) {
                left = words[i].substr(0, j);
                right = words[i].substr(j, words[i].size() - j);
                if (map.find(left) != map.end() && map[left] != i && isPalindrome(right)) {
                    res.push_back({i, map[left]});
                }
                if (map.find(right) != map.end() && map[right] != i && isPalindrome(left)) {
                    res.push_back({map[right], i});
                }
            }
        }
        return res;
    }

    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) { return false; }
        }
        return true;
    }
};
