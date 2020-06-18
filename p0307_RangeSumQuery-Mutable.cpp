using namespace std;

// Traverse from i to j. Time complexity of construct() is O(n) and that of sumRange() is O(n). Space complexity is O(1).
class NumArray {
private:
    vector<int> num;
public:
    NumArray(vector<int> &nums) {
        num = nums;
    }

    void update(int i, int val) {
        num[i] = val;
    }

    int sumRange(int i, int j) {
        int sum = 0;
        for (int k = i; k <= j; k++) {
            sum += num[k];
        }
        return sum;
    }
};