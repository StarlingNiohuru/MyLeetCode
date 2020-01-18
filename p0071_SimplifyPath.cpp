#include <vector>
#include <sstream>

using namespace std;

// Use a stack to store every node's name.(actually in this problem a vector can be more convenient).
// Time complexity is O(n).
class Solution {
public:
    string simplifyPath(string path) {
        string res, temp;
        vector<string> stk;
        stringstream ss(path);
        while (getline(ss, temp, '/')) {
            if (temp == "" || temp == ".") continue;
            if (temp == ".." && !stk.empty()) stk.pop_back();
            if (temp != "..") stk.push_back(temp);
        }
        for (string s:stk) res += "/" + s;
        if (res.empty()) res = "/";
        return res;
    }
};