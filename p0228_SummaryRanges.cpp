#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> res;
        int startNum, endNum;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) startNum = nums[i];
            if (i + 1 == nums.size() || nums[i] + 1 < nums[i + 1]) {
                endNum = nums[i];
                if (startNum == endNum) res.push_back(to_string(startNum));
                else res.push_back(to_string(startNum) + "->" + to_string(endNum));
                if (i + 1 < nums.size()) startNum = nums[i + 1];
            }
        }
        return res;
    }
};