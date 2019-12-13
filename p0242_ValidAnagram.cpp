#include <vector>

using namespace std;

// Use 2 vectors to store frequency of 26 characters (better than hash table here)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> sMap(26, 0);
        vector<int> tMap(26, 0);
        for (int i = 0; i < s.size(); i++) {
            sMap[s[i] - 'a']++;
            tMap[t[i] - 'a']++;
        }
        int conditionsMeet = 0;
        for (int i = 0; i < 26; i++)
            if (sMap[i] == tMap[i]) conditionsMeet++;
        return conditionsMeet == 26;
    }
};