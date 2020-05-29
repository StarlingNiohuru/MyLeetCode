#include <unordered_map>

using namespace std;

// If we simply accumulate from i to j, we will get a TLE. A better way is to use a vector sum[i] which represents the
// sum from num[0] to num[i-1]. We can have sumRange(i,j)=sum[j+1]-sum[i]. Time complexity of construct() is O(n) and
// that of sumRange() is O(1). Space complexity is O(n).
class NumArray {
private:
    vector<int> sum;
public:
    NumArray(vector<int> &nums) {
        sum.push_back(0);
        for (int num:nums)
            sum.push_back(sum.back() + num);
    }

    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
};