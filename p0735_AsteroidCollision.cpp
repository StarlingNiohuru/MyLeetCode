#include <vector>

using namespace std;

// Use a stack
class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        vector<int> res;
        int lastAster;
        for (int newAster:asteroids) {
            if (newAster > 0) res.push_back(newAster);
            else {
                while (!res.empty() && res.back() > 0 && res.back() + newAster < 0) res.pop_back();
                if (res.empty() || res.back() < 0) res.push_back(newAster);
                else if (res.back() + newAster == 0) res.pop_back();
            }
        }
        return res;
    }
};