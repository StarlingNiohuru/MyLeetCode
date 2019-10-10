#include <string>
#include <stack>

using namespace std;

//use a stack to replace "abc". performance is much better
class Solution {
public:
    bool isValid(string S) {
        stack<char> s;
        for (char c:S) {
            if (c == 'c') {
                if (s.size() >= 2 && s.top() == 'b') {
                    s.pop();
                    if (s.top() == 'a') s.pop();
                    else return false;
                } else return false;

            } else s.push(c);
        }
        return s.empty();
    }
};

//find and remove "abc" until there is no "abc"
class Solution2 {
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