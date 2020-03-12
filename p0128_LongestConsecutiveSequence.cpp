#include <vector>
#include <unordered_set>


using namespace std;

// Use hash set to store elements in nums. Then check every element num whether num-1 in set. If not, it means num is
// a beginning number of a streak. Then we check num+1, num+2,...until it's not in set and save the count. At last find
// the max count. Time complexity is O(n) and space complexity is O(n).
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int res = 0, count = 0;
        unordered_set<int> numSet;
        for (int num:nums) numSet.insert(num);
        for (int num:nums)
            if (numSet.count(num - 1) == 0) {
                count = 1;
                while (numSet.count(++num)) count++;
                res = max(res, count);
            }
        return res;
    }
};