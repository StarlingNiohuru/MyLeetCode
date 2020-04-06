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

// Boyer-Moore Majority Vote Algorithm. Since the majority > n/2, positive vote of majority must be >0 at last.
// Time complexity is O(n). Space complexity is O(1).
class Solution2 {
public:
    int majorityElement(vector<int> &nums) {
        int res = 0, count = 0;
        for (int num:nums) {
            if (count == 0) res = num;
            if (res == num) count++;
            else count--;
        }
        return res;
    }
};