using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n > 0) {
            int reminder = (n - 1) % 26;
            char c = (char) (reminder + 'A');
            res = c + res;
            n = (n - 1) / 26;
        }
        return res;
    }
};