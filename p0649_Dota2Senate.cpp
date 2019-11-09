
using namespace std;

// the variable 'deprived' is used to count that how many Radiant or Dire senators are baned temporarily.
// At first if we see a R senator, make deprived++. Then when we meet next D senator, set him 'X' and deprived--.
// Vice versa to D senator.
class Solution {
public:
    string predictPartyVictory(string senate) {
        int deprived = 0;
        bool RadiantExist = true, DireExist = true;
        while (RadiantExist && DireExist) {
            RadiantExist = false, DireExist = false;
            for (int i = 0; i < senate.size(); i++) {
                if (senate[i] == 'R') {
                    RadiantExist = true;
                    if (deprived < 0) senate[i] = 'X';
                    deprived++;
                }
                if (senate[i] == 'D') {
                    DireExist = true;
                    if (deprived > 0) senate[i] = 'X';
                    deprived--;
                }
            }
        }
        return RadiantExist ? "Radiant" : "Dire";
    }
};