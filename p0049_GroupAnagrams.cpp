#include <vector>
#include <unordered_map>

using namespace std;

// Use hash table to record all the strings (value: ["abd","bad"...]) with the same char frequency (key: "#1#1#0#1...").
// Time complexity is O(n*k) where n is the length of strs, k is the max of every string. But it looks slow...
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> gMap;
        for (string s:strs) {
            vector<int> sMap(26, 0);
            string sKey;
            for (char c : s) sMap[c - 'a']++;
            for (int i:sMap) sKey += '#' + to_string(i);
            if (gMap.count(sKey)) gMap[sKey].push_back(s);
            else gMap[sKey] = {s};
        }
        for (auto vec:gMap)
            res.push_back(vec.second);
        return res;
    }

};