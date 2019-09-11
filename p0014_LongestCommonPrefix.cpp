using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";
        string res = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while (res[j] == strs[i][j] && j < strs[i].size()) j++;
            res = strs[i].substr(0, j);
        }
        return res;
    }
};