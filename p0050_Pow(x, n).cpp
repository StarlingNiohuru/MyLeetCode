using namespace std;

// n can be represent as n = b0*pow(2,0) + b1*pow(2,1)...bk*pow(2,k) where bk= 0 or 1.
// So pow(x,n) = pow(x,pow(2,i))*...*pow(x,pow(2,j)) where every bi,bj=1.
// Because pow(x,pow(2,i+1))=pow(x,pow(2,i)*pow(x,pow(2,i), every step we let new_product = product*product and let
// answer = answer*new_product. Time complexity is O(log(n)).
class Solution {
public:
    double myPow(double x, int n) {
        long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double res = 1, tempProduct = x;
        for (long i = N; i > 0; i /= 2) {
            if (i % 2 == 1) res *= tempProduct;
            tempProduct = tempProduct * tempProduct;
        }
        return res;
    }
};
