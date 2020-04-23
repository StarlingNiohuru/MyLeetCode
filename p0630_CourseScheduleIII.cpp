#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Given 2 courses, when d1<=d2, we can prove choosing course 1 is always better than course 2. So sort the courses list
// by d. Then use a heep and check every element one by one. If the new element x can be added to the end without
// exceeding dx, push tx into the heap. If not, find the max ty in the heap and replace it by tx. (We can prove x must be fit)
// At last heap's size is the answer. Time complexity is O(n*log(n)). Space complexity is O(n).
class Solution {
public:
    int scheduleCourse(vector<vector<int>> &courses) {
        sort(courses.begin(), courses.end(), [](vector<int> a, vector<int> b) { return a.back() < b.back(); });
        priority_queue<int> pq;
        int currEnd = 0;
        for (auto &course : courses) {
            pq.push(course[0]);
            currEnd += course[0];
            if (currEnd > course[1]) {
                currEnd -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};