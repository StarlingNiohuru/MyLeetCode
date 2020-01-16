#include <vector>
#include <unordered_map>

using namespace std;

// hash table. When building for example a word "apple", we will insert {"#pple":"a"}, {"a#ple":"p"}, {"ap#le":"p"},
// {"app#e":"l"}, {"appl#":"e"} into the map. If the dict has 2 similar words like "apple" and "apply", we just need to
// change {"appl#":"e"} to {"appl#":"#"} because the last character could be anyone now. Time complexity of bulidDict()
// is O(sum(li)) where li is the length of word[i] and of search() is O(k) where k is the length of the word.
class MagicDictionary {
public:
    unordered_map<string, char> magicMap;

    MagicDictionary() {

    }

    void buildDict(vector<string> dict) {
        char temp;
        for (string word:dict) {
            for (int i = 0; i < word.size(); i++) {
                temp = word[i];
                word[i] = '#';
                if (!magicMap.count(word)) magicMap[word] = temp;
                else if (magicMap[word] != temp) magicMap[word] = '#';
                word[i] = temp;
            }
        }
    }

    bool search(string word) {
        char temp;
        for (int i = 0; i < word.size(); i++) {
            temp = word[i];
            word[i] = '#';
            if (magicMap.count(word) && magicMap[word] != temp) return true;
            word[i] = temp;
        }
        return false;
    }
};