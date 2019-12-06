#include <vector>
#include <unordered_map>

using namespace std;

// Use 2 hashmaps. One is to record the frequency of nums. Another is used to count the num of subarrays which end at i.
class Solution {
public:
    bool isPossible(vector<int> &nums) {
        unordered_map<int, int> frequentMap;
        unordered_map<int, int> tailsMap;
        for (int num:nums) frequentMap[num]++;
        for (int num:nums) {
            if (frequentMap[num] == 0) continue;
            else if (tailsMap[num - 1] > 0) {
                tailsMap[num - 1] -= 1;
                tailsMap[num] += 1;
            } else if (frequentMap[num + 1] > 0 && frequentMap[num + 2] > 0) {
                frequentMap[num + 1] -= 1;
                frequentMap[num + 2] -= 1;
                tailsMap[num + 2] += 1;
            } else return false;
            frequentMap[num] -= 1;
        }
        return true;
    }
};