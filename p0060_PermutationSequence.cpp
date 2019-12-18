#include <vector>
#include <utility>
#include <string>

using namespace std;

// similar to p0031. Use nextPermutation() k-1 step. Time complexity is O(n* (k-1) % factorial[n]). slow
class Solution {
private:
    void nextPermutation(vector<int> &nums) {
        int i = nums.size() - 1, j;
        while (i > 0 && nums[i] <= nums[i - 1]) i--;
        j = i - 1;
        if (j >= 0) {
            while (i < nums.size() - 1 && nums[i + 1] > nums[j]) i++;
            swap(nums[i], nums[j]);
        }
        i = j + 1, j = nums.size() - 1;
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }

public:
    string getPermutation(int n, int k) {
        string res;
        vector<int> nums;
        for (int i = 0; i < n; i++) nums.push_back(i + 1);
        vector<int> factorial = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        k = (k - 1) % factorial[n - 1] + 1;
        for (int i = 1; i < k; i++) nextPermutation(nums);
        for (int i = 0; i < n; i++) res += to_string(nums[i]);
        return res;
    }
};