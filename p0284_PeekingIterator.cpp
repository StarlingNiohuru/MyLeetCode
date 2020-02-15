#include <vector>

using namespace std;

class Iterator {
    struct Data;
    Data *data;
public:
    Iterator(const vector<int> &nums);

    Iterator(const Iterator &iter);

    virtual ~Iterator();

    int next();

    bool hasNext() const;
};

// peek() operation means getting next element without going forward. We use 2 variables to record the status before
// going forward.
class PeekingIterator : public Iterator {
private:
    int savedNext;
    bool savedHasNext;
public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums) {
        savedHasNext = Iterator::hasNext();
        if (savedHasNext) savedNext = Iterator::next();
    }

    int peek() {
        return savedNext;
    }

    int next() {
        int res = savedNext;
        savedHasNext = Iterator::hasNext();
        if (savedHasNext) savedNext = Iterator::next();
        return res;
    }

    bool hasNext() const {
        return savedHasNext;
    }
};