#include <list>
#include <unordered_map>

using namespace std;

// For this problem, we need a new data structure which has properties of both hash table and the double-linked list.
// cacheMap is used to record key and value; cacheList is a double-linked list to record the order of cache key;
// cachePos keeps key and its position(iterator) of cacheList. They can let get() and put() finished in O(1) complexity.
class LRUCache {
private:
    int capacity;
    list<int> cacheList;
    unordered_map<int, int> cacheMap;
    unordered_map<int, list<int>::iterator> cachePos;

    void use(int key) {
        if (cachePos.count(key)) cacheList.erase(cachePos[key]);
        else if (cacheList.size() >= capacity) {
            int old = cacheList.back();
            cacheList.pop_back();
            cacheMap.erase(old);
            cachePos.erase(old);
        }
        cacheList.push_front(key);
        cachePos[key] = cacheList.begin();
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
    }

    int get(int key) {
        if (cacheMap.count(key)) {
            use(key);
            return cacheMap[key];
        } else return -1;
    }

    void put(int key, int value) {
        use(key);
        cacheMap[key] = value;
    }
};