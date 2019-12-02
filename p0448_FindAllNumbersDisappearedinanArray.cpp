#include <vector>
#include <utility>

using namespace std;

// Swap the nums to sort the list as [1,2,3,4,3,6,...]. Then pick up the elements which don't satisfy nums[i] != i + 1
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
            while (nums[i] != i + 1 && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != i + 1) res.push_back(i + 1);
        return res;
    }
};