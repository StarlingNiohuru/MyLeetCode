using namespace std;

int guess(int num);

// Binary search. notice that we use mid = low + (high - low)/2 to avoid overflow. Time complexity is O(log(n)).
class Solution {
public:
    int guessNumber(int n) {
        int lo = 1, hi = n, mid;
        while (true) {
            mid = lo + (hi - lo) / 2; // avoid int overflow
            if (guess(mid) == 0) return mid;
            else if (guess(mid) == -1) hi = mid - 1;
            else lo = mid + 1;
        }
    }
};