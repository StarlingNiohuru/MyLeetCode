using namespace std;

//Because every prime factor 5 in n! means one more 0 behind, we need to find how many multiples of 5,25,125... in the
// factors of n!. Time complexity is O(log(n)).
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n > 0) {
            n /= 5;
            res += n;
        }
        return res;
    }
};