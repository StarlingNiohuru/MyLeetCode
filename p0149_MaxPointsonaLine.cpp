#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

// For each point p, calculate all slopes of the p and other points. If slope of (p,p1)==slope of(p,p2), that means
// p,p1,p2 on the same line. Use a hash table to count the number of slopes. Then find the max. (Notice duplicate case
// when p1==p) The final answer is max of the max of every p. Time complexity is O(n^2). Space complexity is O(n).
class Solution {
private:
    int greatestCommonDivisor(int a, int b) {
        while (b) {
            a = a % b;
            swap(a, b);
        }
        return a;
    }

public:
    int maxPoints(vector<vector<int>> &points) {
        if (points.empty()) return 0;
        int n = points.size(), res = 1;
        for (int i = 0; i < n; i++) {
            unordered_map<string, int> slopeMap;
            int dup = 1;
            for (int j = i + 1; j < n; j++) {
                if (points[j][0] == points[i][0] && points[j][1] == points[i][1]) dup++;
                else {
                    int dx = points[j][0] - points[i][0], dy = points[j][1] - points[i][1],
                            gcd = greatestCommonDivisor(dx, dy);
                    slopeMap[to_string(dx / gcd) + '/' + to_string(dy / gcd)]++;
                }
                res = max(res, dup);
                for (auto k:slopeMap) res = max(res, k.second + dup);
            }
        }
        return res;
    }
};