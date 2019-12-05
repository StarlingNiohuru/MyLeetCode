#include <unordered_map>

using namespace std;

// Use a hashmap to count frequency.
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> frequentMap;
        for (char x:s) frequentMap[x]++;
        for (int i = 0; i < s.size(); i++)
            if (frequentMap[s[i]] == 1) return i;
        return -1;
    }
};