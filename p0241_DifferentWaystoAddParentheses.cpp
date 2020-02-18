#include <vector>
#include <string>

using namespace std;

// divide and conquer with recursive way. similar to p0095 and p0096. The operations '+','-','*' can be considered as
// tree nodes. Time complexity is O(4^n/sqrt(n)) and space complexity is O(4^n/sqrt(n)), which is the Catalan number.
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> l = diffWaysToCompute(input.substr(0, i));
                vector<int> r = diffWaysToCompute(input.substr(i + 1));
                for (auto &j : l)
                    for (auto &k : r) {
                        if (input[i] == '+') res.push_back(j + k);
                        else if (input[i] == '-') res.push_back(j - k);
                        else res.push_back(j * k);
                    }
            }
        }
        if (res.empty()) res.push_back(stoi(input));
        return res;
    }
};