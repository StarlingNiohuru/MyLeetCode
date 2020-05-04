#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

// similar to p0205. Use i + 1 as the value to avoid 0 because hash map will assign default 0 value for non-existing keys.
// Time complexity is O(n). Space complexity is O(n).
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<int> p2i(26, 0);
        unordered_map<string, int> s2i;
        istringstream iss(str);
        int i = 0, n = pattern.size();
        for (string word; iss >> word; i++) {
            if (i == n || p2i[pattern[i] - 'a'] != s2i[word]) return false;
            p2i[pattern[i] - 'a'] = s2i[word] = i + 1;
        }
        return i == n;
    }
};