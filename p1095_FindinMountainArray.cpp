using namespace std;

class MountainArray {
public:
    int get(int index);

    int length();
};

// Binary search 3 times. First find the peak of the mountain array. Then search the first half and the latter half.
// Time complexity is O(log(n)). Space complexity is O(1).
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int lo = 0, hi = mountainArr.length() - 1, mi, peak;
        while (lo < hi) {
            mi = lo + (hi - lo) / 2;
            if (mountainArr.get(mi) < mountainArr.get(mi + 1)) lo = mi + 1;
            else hi = mi;
        }
        peak = lo;
        lo = 0, hi = peak;
        while (lo <= hi) {
            mi = lo + (hi - lo) / 2;
            if (mountainArr.get(mi) < target) lo = mi + 1;
            else if (mountainArr.get(mi) == target) return mi;
            else hi = mi - 1;
        }
        lo = peak, hi = mountainArr.length() - 1;
        while (lo <= hi) {
            mi = lo + (hi - lo) / 2;
            if (mountainArr.get(mi) > target) lo = mi + 1;
            else if (mountainArr.get(mi) == target) return mi;
            else hi = mi - 1;
        }
        return -1;
    }
};