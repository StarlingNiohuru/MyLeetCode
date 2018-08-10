#include <iostream>
#include <vector>

using namespace std;

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);
    cout << result[0] << "," << result[1] << endl;
    return 0;
}