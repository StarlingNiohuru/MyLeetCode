#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// N is so large that it may cause time exceeded or memory overflow problem. So we need to use hash tables like rows,
// cols, diag1s, diag2s to record how many time the lines are illuminated. And we also need a set to save lumps' position
// instead of a 2D array. Time complexity is O(l+q) where l is the number of lumps and q is the number of queries.
// Space complexity is O(l+q) too.
struct pairHash {
    size_t operator()(const pair<int, int> &x) const { return x.first ^ x.second; }
};

class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>> &lamps, vector<vector<int>> &queries) {
        vector<int> res;
        unordered_map<int, int> rows, cols, diag1s, diag2s;
        unordered_set<pair<int, int>, pairHash> litLamps;// we can't use set with a pair directly in C++
        for (vector<int> lamp:lamps) {
            rows[lamp[0]]++;
            cols[lamp[1]]++;
            diag1s[lamp[0] + lamp[1]]++;
            diag2s[lamp[0] - lamp[1]]++;
            litLamps.insert({lamp[0], lamp[1]});
        }
        for (vector<int> query:queries) {
            if (rows[query[0]] + cols[query[1]] + diag1s[query[0] + query[1]] + diag2s[query[0] - query[1]] > 0) {
                res.push_back(1);
                for (int i = max(query[0] - 1, 0); i <= query[0] + 1 && i < N; i++)
                    for (int j = max(query[1] - 1, 0); j <= query[1] + 1 && j < N; j++)
                        if (litLamps.erase({i, j})) {
                            rows[i]--;
                            cols[j]--;
                            diag1s[i + j]--;
                            diag2s[i - j]--;
                        }
            } else res.push_back(0);// we don't need to erase lamps around when query point is not lit.
        }
        return res;
    }
};