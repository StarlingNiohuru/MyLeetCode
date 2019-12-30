#include <string>

using namespace std;

// iteration
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int k = 1; k < n; k++) {
            string temp = "";
            for (int i = 0; i < res.size(); i++) {
                int count = 1;
                while (i < res.size() - 1 && res[i] == res[i + 1]) {
                    count++;
                    i++;
                }
                temp += to_string(count) + res[i];
            }
            res = temp;
        }
        return res;
    }
};