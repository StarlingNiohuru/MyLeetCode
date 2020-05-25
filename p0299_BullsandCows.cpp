#include <unordered_map>

using namespace std;

// Use hash table to count every digit of secret number. Then use it to guess number.
// Time complexity is O(n). Space complexity is O(1).
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        unordered_map<char, int> digitMap;
        for (char c:secret) digitMap[c]++;
        for (int i = 0; i < guess.size(); i++)
            if (secret[i] == guess[i]) {
                bulls++;
                digitMap[guess[i]]--;
            }
        for (int i = 0; i < guess.size(); i++)
            if (secret[i] != guess[i] && digitMap[guess[i]] > 0) {
                cows++;
                digitMap[guess[i]]--;
            }
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};