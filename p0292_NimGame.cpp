using namespace std;

// All the multiple of 4 are guaranteed losing status. Time complexity is O(1).
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};