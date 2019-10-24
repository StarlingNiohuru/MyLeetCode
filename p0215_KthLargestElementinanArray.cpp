#include <vector>
#include <utility>

using namespace std;

// Use Quick Sort to divide the list into 2 parts. The element of front always greater than one of back.
// If the length of front > k, find the back list by quick soft.Vice versa. Until accumulative front = k.
// Average time complexity is O(n). But worst time complexity is O(n*n).
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int n = -1, pivotIndex, left = 0, right = nums.size() - 1;
        do {
            if (n == right) right--; //avoid occasions like nums=[2,2,2], k=1
            n = partition(nums, left, right, left);
            if (n > k - 1) right = n;
            if (n < k - 1) left = n + 1;
        } while (n != k - 1);
        return nums[n];
    }

private:
    int partition(vector<int> &nums, int left, int right, int pivotIndex) {
        int pivot = nums[pivotIndex], first = left;
        swap(nums[left], nums[pivotIndex]);
        while (left <= right) {
            if (nums[left] >= pivot) left++;
            else if (nums[right] < pivot) right--;
            else swap(nums[left], nums[right]);
        }
        swap(nums[first], nums[right]);
        return left - 1;
    }
};