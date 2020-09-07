#include <vector>
#include <unordered_set>

using namespace std;

// 2 pointers with a hash set.Time complexity is O(n).Space complexity is O(1).
class Solution {
public:
    string reverseVowels(string s) {
        unordered_set vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!vowels.count(s[i])) i++;
            else if (!vowels.count(s[j])) j--;
            else swap(s[i++], s[j--]);
        }
        return s;
    }
};