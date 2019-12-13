#include <vector>

using namespace std;

// Use 2 vectors (better than hash table here) to store frequency of every character of s1 and window of s2. The
// s2map represents frequency of every sliding window of s2. conditionsMeet counts how many s2map[char] = s2map[char]
// If conditionsMeet = 26 means answer satisfied. similar to p0076. Time complexity is O(l2) (l2 is the length of s2)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> s1map(26, 0);
        vector<int> s2map(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            s1map[s1[i] - 'a']++;
            s2map[s2[i] - 'a']++;
        }
        int conditionsMeet = 0;
        for (int i = 0; i < 26; i++)
            if (s1map[i] == s2map[i]) conditionsMeet++;
        for (int i = 0; i < s2.size() - s1.size(); i++) {
            if (conditionsMeet == 26) return true;
            else {
                int left = s2[i] - 'a', right = s2[i + s1.size()] - 'a';
                if (s1map[left] == s2map[left]) conditionsMeet--;
                if (s1map[left] == (--s2map[left])) conditionsMeet++;
                if (s1map[right] == s2map[right]) conditionsMeet--;
                if (s1map[right] == (++s2map[right])) conditionsMeet++;
            }
        }
        return conditionsMeet == 26;
    }
};