#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

// Use sliding window with 2 pointers. right moves first until we find a satisfied answer. Then left moves until
// condition unfilled any longer. Repeat until j = s[-1]
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tCount;
        unordered_map<char, int> windowCount;
        for (char c:t) tCount[c]++;
        int i = 0, j = 0, conditionsMeet = 0, allConditionsMeet = tCount.size();
        pair<int, int> res = {-1, s.size()};
        while (j < s.size()) {
            if (tCount.count(s[j])) {
                windowCount[s[j]]++;
                if (windowCount[s[j]] == tCount[s[j]]) conditionsMeet++;
                while (i <= j && conditionsMeet == allConditionsMeet) {
                    if (tCount.count(s[i])) {
                        if (j - i + 1 <= res.second) res = make_pair(i, j - i + 1);
                        if (windowCount[s[i]] == tCount[s[i]]) conditionsMeet--;
                        windowCount[s[i]]--;
                    }
                    i++;
                }
            }
            j++;
        }
        return (res.first == -1) ? "" : s.substr(res.first, res.second);
    }
};