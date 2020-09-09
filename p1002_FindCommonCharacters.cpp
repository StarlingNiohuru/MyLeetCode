#include <vector>

using namespace std;

// Use 26-length vector (or hash table) to record every word's character frequency. As for minFreq, minFreq[i] represents
// the min of all freq[i]s. We can get the final answer from minFreq.Time complexity is O(N).Space complexity is O(min(N)).
class Solution {
public:
    vector<string> commonChars(vector<string> &A) {
        vector<int> freq(26, 0);
        vector<int> minFreq(26, INT32_MAX);
        vector<string> res;
        for (string a:A) {
            for (int &e:freq) e = 0;
            for (char c:a) freq[c - 'a']++;
            for (int i = 0; i < 26; i++)
                minFreq[i] = min(minFreq[i], freq[i]);
        }
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < minFreq[i]; j++)
                res.emplace_back(1, 'a' + i);
        return res;
    }
};