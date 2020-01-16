#include <vector>

using namespace std;

// First check how many words in a line. if charOfWords + numOfWords - 1 > maxWidth, it means the sequence now just
// exceed the maxWidth. we need to calculate gaps by "/" and "%" operation. Notice the situation when only one word in
// a line or we meet the last line, we fill ending with spaces until reaching maxWidth. Time complexity is O(n).
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> res;
        string line, gap;
        int charOfWords = 0, numOfWords = 0, j = 0, numOfSpaces, reminder;
        for (int i = 0; i < words.size(); i++) {
            charOfWords += words[i].size();
            numOfWords++;
            if (charOfWords + numOfWords - 1 > maxWidth) {
                numOfSpaces = maxWidth - charOfWords + words[i].size();
                reminder = (numOfWords > 2) ? numOfSpaces % (numOfWords - 2) : 0;
                if (numOfWords > 2) for (int k = 0; k < numOfSpaces / (numOfWords - 2); k++) gap += ' ';
                for (; j < i; j++) {
                    if (j < i - 1) {
                        line += words[j] + gap;
                        if ((reminder--) > 0) line += ' ';
                    } else line += words[j];
                }
                numOfSpaces = maxWidth - line.size();
                for (int k = 0; k < numOfSpaces; k++) line += ' ';
                res.push_back(line);
                charOfWords = words[i].size();
                numOfWords = 1;
                line = "";
                gap = "";
                j = i;
            }
            if (i == words.size() - 1) {
                for (; j <= i; j++) line += (j == i) ? words[j] : (words[j] + ' ');
                numOfSpaces = maxWidth - line.size();
                for (int k = 0; k < numOfSpaces; k++) line += ' ';
                res.push_back(line);
            }
        }
        return res;
    }
};