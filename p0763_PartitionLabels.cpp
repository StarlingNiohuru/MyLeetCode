#include <vector>
#include <unordered_map>

using namespace std;

// Use a table to record the last index of every character first.
// If a character 'a' in a partition, lastIndex['a'] must be in the same partition. So traverse the string from left
// with lastIndex[] table to find the right end of this partition.
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        unordered_map<char, int> charLastIndex;
        for (int i = 0; i < S.size(); i++)
            charLastIndex[S[i]] = i;
        int partitionStart = 0, partitionEnd = 0;
        for (int i = 0; i < S.size(); i++) {
            partitionEnd = max(charLastIndex[S[i]], partitionEnd);
            if (i == partitionEnd) {
                res.push_back(i - partitionStart + 1);
                partitionStart = i + 1;
            }
        }
        return res;
    }
};