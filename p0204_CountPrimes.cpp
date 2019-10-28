#include <vector>
#include <cmath>

using namespace std;

// Sieve of Eratosthenes, eliminating all the multiples of every prime.
// The min prime factor of m is less than sqrt(m), so we don't need to eliminate a prime's multiples when p > sqrt(n)
class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<bool> primes(n, true);
        for (int i = 2; i < n; i++)
            if (primes[i]) {
                res++;
                if (i < sqrt(n))
                    for (int j = 2 * i; j < n; j = j + i) primes[j] = false;
            }
        return res;
    }
};