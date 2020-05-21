#include <set>

using namespace std;

// Use an AVL Tree (multiset in C++) to keep order and maintain 2 pointers (low median and high median).
// When adding new num, we move the pointers depending on whether the multiset's size is odd or even.
// Time complexity is O(log(n)). Space complexity is O(n).
class MedianFinder {
public:
    multiset<int> s;
    multiset<int>::iterator lowMedian, highMedian;

    MedianFinder() {

    }

    void addNum(int num) {
        int n = s.size();
        s.insert(num);
        if (n == 0) lowMedian = highMedian = s.begin();
        else if (n % 2 == 1) {
            if (num < *lowMedian) lowMedian--;
            else highMedian++;
        } else {
            if (num > *lowMedian && num < *highMedian) {
                lowMedian++;
                highMedian--;
            } else if (num <= *lowMedian)
                lowMedian = --highMedian; // notice: If num = lowMedian, inserted num will be between low and high.
            else lowMedian++;
        }
    }

    double findMedian() {
        return (*lowMedian + *highMedian) * 0.5;
    }
};