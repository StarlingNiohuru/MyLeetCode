#include <algorithm>

using namespace std;

// Reverse the whole string then reverse every word. Traverse string by i and use j to find the end of word.
// For eliminating extra ' ', use k to copy every word from s[i,j] and then reverse it.
// Time complexity is O(n). Space complexity is O(1).
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int k = 0, n = s.size();
        for (int i = 0; i < n; i++)
            if (s[i] != ' ') {
                if (k != 0) s[k++] = ' ';
                int j = i;
                while (j < n && s[j] != ' ') s[k++] = s[j++];
                reverse(s.begin() + k - (j - i), s.begin() + k);
                i = j;
            }
        s.erase(s.begin() + k, s.end());
        return s;
    }
};