#include <vector>

using namespace std;

//Use 2 vectors and sliding window. similar to p0567
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (p.size() > s.size()) return res;
        vector<int> pMap(26, 0);
        vector<int> sMap(26, 0);
        for (int i = 0; i < p.size(); i++) {
            pMap[p[i] - 'a']++;
            sMap[s[i] - 'a']++;
        }
        int conditionsMeet = 0, l, r;
        for (int i = 0; i < 26; i++)
            if (sMap[i] == pMap[i]) conditionsMeet++;
        for (int i = 0; i < s.size() - p.size(); i++) {
            if (conditionsMeet == 26) res.push_back(i);
            l = s[i] - 'a', r = s[i + p.size()] - 'a';
            if (pMap[l] == sMap[l]) conditionsMeet--;
            if (pMap[l] == (--sMap[l])) conditionsMeet++;
            if (pMap[r] == sMap[r]) conditionsMeet--;
            if (pMap[r] == (++sMap[r])) conditionsMeet++;
        }
        if (conditionsMeet == 26) res.push_back(s.size() - p.size());
        return res;
    }
};