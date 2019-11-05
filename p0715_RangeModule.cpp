#include <map>
#include <algorithm>

using namespace std;

// Using vector (complexity O(n)) may cause Time Limit Exceeded. So use a ordered map( red-black tree) instead.
// To finish add() and remove(), we need to find a series intervals [i,j] which covers given [left, right]. Then judge
// the both boundaries by min(j.first, left) and max(j.second, right).
// The complexity of add() or remove() is O(k) where k is the number of intervals of the range[left,right]，
// The complexity of query() is O(log(n)) where n in the number of all intervals。
class RangeModule {
    map<int, int> intervals;
public:
    RangeModule() {
    }

    void addRange(int left, int right) {
        auto l = intervals.upper_bound(left), r = intervals.upper_bound(right);
        if (l != intervals.begin())
            if ((--l)->second < left) l++;
        if (l != r) {
            left = min(left, l->first);
            right = max(right, (--r)->second);
            intervals.erase(l, ++r);
        }
        intervals[left] = right;
    }

    bool queryRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        return it != intervals.begin() && (--it)->second >= right;
    }

    void removeRange(int left, int right) {
        auto l = intervals.upper_bound(left), r = intervals.upper_bound(right);
        if (l != intervals.begin())
            if ((--l)->second < left) l++;
        if (l != r) {
            int lb = min(left, l->first), rb = max(right, (--r)->second);
            intervals.erase(l, ++r);
            if (lb < left) intervals[lb] = left;
            if (rb > right) intervals[right] = rb;
        }
    }
};