#include <vector>

using namespace std;

// If the last 2 bits are [...0,0], it must be true. If not, we need to count how many '1' before 0 at the last bit. If
// the count number is even, the answer is true. Otherwise it is false. Time complexity is O(n).
class Solution {
public:
    bool isOneBitCharacter(vector<int> &bits) {
        if (bits.size() == 1) return true;
        if (bits[bits.size() - 2] == 0) return true;
        int count = 0;
        for (int i = bits.size() - 2; i >= 0; i--) {
            if (bits[i] == 1) {
                count++;
            } else break;
        }
        return count % 2 == 0;
    }
};