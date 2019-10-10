#include <string>

using namespace std;

//find and remove "abc" until there is no "abc"
class Solution {
public:
    bool isValid(string S) {
        while (!S.empty()) {
            auto i = S.find("abc");
            if (i == string::npos) return false;
            else S.erase(i, 3);
        }
        return S.empty();
    }
};