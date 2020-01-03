using namespace std;

// Mod calculation has a formulation: (a*b)%c = ((a%c)*(b%c))%c, which can be used to implement quickPow() function.
// And at any multiplication we always can % 1337 to simplify calculation. To superPow we use cumulative product, for example:
// 6^1235 = 6^1000*6^200*6^30*6^5, in first step 6^1, second step ((6^1)^10)*6^2, third step ((((6^1)^10)*6^2)^10)*6^3,
// which means every step we have new_cumulative_product = pow(6,10)*last_cumulative_product*pow(6,new).
// Time complexity is O(n), where n is the length of b.
class Solution {
public:
    int superPow(int a, vector<int> &b) {
        int res = 1;
        for (int num:b)
            res = (quickPow(res, 10, 1337) * quickPow(a, num, 1337)) % 1337;
        return res;
    }

private:
    int quickPow(int a, int b, int c) {
        int res = 1;
        a = a % c;
        while (b != 0) {
            if (b & 1) res = (res * a) % c;
            a = (a * a) % c;
            b >>= 1;
        }
        return res;
    }
};