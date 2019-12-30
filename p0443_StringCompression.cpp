#include <string>

using namespace std;

// 2 pointers. One read another write. Time complexity is O(n).
class Solution {
public:
    int compress(vector<char> &chars) {
        int j = 0;
        for (int i = 0; i < chars.size(); i++) {
            int count = 1;
            while (i < chars.size() - 1 && chars[i] == chars[i + 1]) {
                count++;
                i++;
            }
            chars[j] = chars[i];
            j++;
            if (count > 1) {
                for (char c:to_string(count)) {
                    chars[j] = c;
                    j++;
                }
            }
        }
        return j;
    }
};