#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
        int res = 0;
        unordered_map<int, int> map;
        for (int a:A) {
            for (int b:B) { ++map[a + b]; }
        }
        for (int c:C) {
            for (int d:D) {
                auto got = map.find(0 - c - d);
                if (got != map.end()) {
                    res += map[0 - c - d];
                }
            }
        }
        return res;
    }
};

