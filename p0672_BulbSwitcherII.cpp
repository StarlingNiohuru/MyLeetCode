using namespace std;

// We can prove that the first 3 lights can determine all the rest of ones. So we only need to consider n in [0,3]. And
// for each operation, even times won't change the lights and flip all + flip even = flip odd. So only m in [0,3] is
// needed to consider. We can enumerate every case. Time and Space complexity are O(1).
class Solution {
public:
    int flipLights(int n, int m) {
        if (m == 0 || n == 0) return 1;
        if (n == 1) return 2;
        if (n == 2) return (m == 1) ? 3 : 4;
        if (m == 1) return 4;
        return (m == 2) ? 7 : 8;
    }
};