#include <vector>
#include <map>

using namespace std;

// Use a tree map to record intervals. Time complexity of add() is log(n)
class SummaryRanges {
    map<int, int> intervals;
public:
    SummaryRanges() {

    }

    void addNum(int val) {
        if (intervals.empty()) {
            intervals[val] = val;
            return;
        }
        bool closeToLeft = false, closeToRight = false;
        int leftValue, rightValue;
        auto itr = intervals.upper_bound(val), itl = (itr == intervals.begin()) ? intervals.end() : prev(itr);
        if (itl != intervals.end() && itl->second >= val) return;
        if (itr != intervals.end() && val + 1 == itr->first) closeToRight = true;
        if (itl != intervals.end() && itl->second + 1 == val) closeToLeft = true;
        if (closeToLeft && closeToRight) {
            leftValue = itl->first, rightValue = itr->second;
            intervals.erase(itl, next(itr));
        } else if (closeToLeft) {
            leftValue = itl->first, rightValue = val;
            intervals.erase(itl);
        } else if (closeToRight) {
            leftValue = val, rightValue = itr->second;
            intervals.erase(itr);
        } else leftValue = val, rightValue = val;
        intervals[leftValue] = rightValue;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int> > res;
        for (auto &interval : intervals)
            res.push_back({interval.first, interval.second});
        return res;
    }
};