#include <vector>
#include <unordered_map>

using namespace std;

// We can find every set of letters corresponds to a max length of words.(for example: "ab","abbb","aabababb" we can record
// as set(["a","b"]):8) We also can use a 2-bit mask representing a set of letters (for example [...,0,1,1] means having a,b
// by mask |= 1 << (c - 'a')). Then traverse words[]. For each word, we check it between all in maxSetLen<> and update them,
// finding the final answer max(word.size() * maxSetLen[mask]).Time complexity is O(n^2) and Space complexity is O(n).
class Solution {
public:
    int maxProduct(vector<string> &words) {
        unordered_map<int, int> maxSetLen;
        int res = 0;
        for (string word:words) {
            int mask = 0;
            for (char c:word) mask |= 1 << (c - 'a');
            maxSetLen[mask] = max(maxSetLen[mask], (int) word.size());
            for (auto x : maxSetLen)
                if (!(x.first & mask))
                    res = max(res, (int) word.size() * x.second);
        }
        return res;
    }
};