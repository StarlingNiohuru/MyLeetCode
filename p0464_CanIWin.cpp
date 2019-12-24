#include <vector>

using namespace std;

// Use dp and dfs. We can use binary number to represent status of choosable numbers.(For example 13(01101) means
// 1,3 and 4 are already chosen.) Then dp[stat][desired] can represent a stat of game.But stat only correspond to
// desired so dp[stat] is enough to represent a status. Then use dfs to calculate dp[0]. If any dp[next stat] is false,
// dp[stat] must be true.
class Solution {
private:
    bool dfs(int maxChoosableInteger, int desiredTotal, int stat, vector<int> &dp) {
        if (dp[stat] != 0) return dp[stat] == 1;
        bool isWin = false;
        for (int i = 1; i <= maxChoosableInteger; i++) {
            if ((stat & (1 << (i - 1))) == 0) {
                if (i >= desiredTotal) isWin = true;
                else isWin = !dfs(maxChoosableInteger, desiredTotal - i, stat ^ (1 << (i - 1)), dp);
                if (isWin) break;
            }
        }
        dp[stat] = isWin ? 1 : -1;
        return isWin;
    }

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        vector<int> dp(1 << maxChoosableInteger, 0);
        return dfs(maxChoosableInteger, desiredTotal, 0, dp);
    }
};