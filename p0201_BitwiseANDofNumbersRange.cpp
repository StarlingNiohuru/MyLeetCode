using namespace std;

// We need to find the leftmost bit b where m and n is different. The bits on the left of b must be the same and the ones
// on the right of b must have a all-0 consequence of bitwise AND operation in [m,n]. So left part + 000.. is the answer.
// Time complexity is O(n). Space complexity is O(1).
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            count++;
        }
        return m << count;
    }
};