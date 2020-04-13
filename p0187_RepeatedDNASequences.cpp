#include <vector>
#include <unordered_map>

using namespace std;

// Use hash table to count the number of substring in every slide window. Time complexity is O(n), space complexity is O(n).
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> seqMap;
        for (int i = 0; i + 10 - 1 < s.size(); i++)
            seqMap[s.substr(i, 10)]++;
        vector<string> res;
        for (const auto &p:seqMap)
            if (p.second > 1) res.push_back(p.first);
        return res;
    }
};