using namespace std;

// Every step, count the number of "1"s from one bit of 1,2,3...n. For example first we take 1,11,21,31... into account;
// Second, count 10,11,12...110,111,112...210,211,212...; and so on. For every bit, we have formulation:
// numbers of bit k = n / (i * 10) * i + min(max(n % (i * 10) - i + 1, 0), i) where i=k^10.(0<=k,i<=n)
// Time complexity is O(log(n)).
class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        for (long i = 1; i <= n; i *= 10)
            res += n / (i * 10) * i + min(max(n % (i * 10) - i + 1, 0L), i);
        return res;
    }
};