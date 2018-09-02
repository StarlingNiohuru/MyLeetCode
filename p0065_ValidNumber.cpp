#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int currentState, charType;
        vector<unordered_map<int, int>> state;
        // There are 9 states.State[i] represents state i.Internal key means next char type,value means next state.
        // charType:{0:blank,1:sign,2:digit,3:dot,4:exponent,-1:invalid}
        state = {
                {},
                {{0, 1}, {1, 2}, {2, 3}, {3, 4}},
                {{2, 3}, {3, 4}},
                {{2, 3}, {3, 5}, {4, 6}, {0, 9}},
                {{2, 5}},
                {{2, 5}, {4, 6}, {0, 9}},
                {{1, 7}, {2, 8}},
                {{2, 8}},
                {{2, 8}, {0, 9}},
                {{0, 9}}
        };
        unordered_set<int> validState = {3, 5, 8, 9};
        currentState = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') { charType = 0; }
            else if (s[i] == '+' || s[i] == '-') { charType = 1; }
            else if (s[i] >= '0' && s[i] <= '9') { charType = 2; }
            else if (s[i] == '.') { charType = 3; }
            else if (s[i] == 'e') { charType = 4; }
            else { charType = -1; }
            if (state[currentState].count(charType) == 0) { return false; }
            else { currentState = state[currentState][charType]; }
        }
        if (validState.count(currentState) == 0) { return false; }
        else { return true; }
    }
};
