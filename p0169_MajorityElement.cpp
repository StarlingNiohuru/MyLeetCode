#include <vector>
#include <unordered_map>

using namespace std;

// Use hash table to count frequency of numbers. Time complexity is O(n). Space complexity is O(n).
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> count;
        int res = 0, maxCount = 0;
        for (int num:nums) {
            count[num]++;
            if (count[num] > maxCount) {
                res = num;
                maxCount = count[num];
            }
        }
        return res;
    }
};