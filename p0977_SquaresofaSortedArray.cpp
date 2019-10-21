#include <vector>
#include <cmath>

using namespace std;

// use 2 pointers from both sides
class Solution {
public:
    vector<int> sortedSquares(vector<int> &A) {
        vector<int> res(A);
        int pointer = A.size() - 1, pointer1 = 0, pointer2 = A.size() - 1;
        while (pointer1 <= pointer2) {
            if (abs(A[pointer1]) > abs(A[pointer2])) {
                res[pointer] = A[pointer1] * A[pointer1];
                pointer1++;
            } else {
                res[pointer] = A[pointer2] * A[pointer2];
                pointer2--;
            }
            pointer--;
        }
        return res;
    }
};