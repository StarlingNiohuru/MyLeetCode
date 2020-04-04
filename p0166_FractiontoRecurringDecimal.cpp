#include <unordered_map>
#include <cstdlib>

using namespace std;

// Use a hash table to record the index of reminder of every step. If reminder appears again, break the loop and
// insert '(' at the index before (reminderPos[reminder]). And add ')' at the end.
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string res;
        if (numerator > 0 ^ denominator > 0) res += '-';
        long n = labs(numerator), d = labs(denominator), reminder = n % d;
        res += to_string(n / d);
        if (reminder == 0) return res;
        else res += '.';
        unordered_map<int, int> reminderPos;
        while (reminder && !reminderPos.count(reminder)) {
            reminderPos[reminder] = res.size();
            reminder *= 10;
            res += to_string(reminder / d);
            reminder %= d;
        }
        if (reminderPos.count(reminder)) {
            res.insert(reminderPos[reminder], "(");
            res += ')';
        }
        return res;
    }
};