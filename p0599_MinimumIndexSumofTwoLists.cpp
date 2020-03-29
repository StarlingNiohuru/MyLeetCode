#include <vector>
#include <unordered_map>

using namespace std;

// Use hash table to record every string and index in list1. Then check string in list2. If the string in map,
// calculate the sum of indexes and add it into answer if the sum<min sum.
// Time complexity is O(n1+n2). Space complexity is O(n1*x1) where x1 is the average length of words in list1.
class Solution {
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
        vector<string> res;
        unordered_map<string, int> sMap;
        for (int i = 0; i < list1.size(); i++) sMap[list1[i]] = i;
        int minSum = INT32_MAX, sum;
        for (int i = 0; i < list2.size(); i++)
            if (sMap.count(list2[i])) {
                sum = sMap[list2[i]] + i;
                if (sum < minSum) {
                    res.clear();
                    res.push_back(list2[i]);
                    minSum = sum;
                } else if (sum == minSum)
                    res.push_back(list2[i]);
            }
        return res;
    }
};