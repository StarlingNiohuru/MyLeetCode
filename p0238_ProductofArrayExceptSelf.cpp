class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
//        using 2 arrays,one records product before nums[i],the other records product after nums[i], at last merge 2 arrays into 1
        int front = 1, back = 1, n = nums.size();
        vector<int> res(n, 1);
        res[0] = 1;
        for (int i = 0; i < n; i++) {
            res[i] *= front;
            front *= nums[i];
            res[n - 1 - i] *= back;
            back *= nums[n - 1 - i];
        }
        return res;
    }
};

