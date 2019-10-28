#include <vector>
#include <utility>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// Find the min of the first listnodes of k linked lists by a heap every step
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *res = new ListNode(0);
        ListNode *pointer = res;
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<>> pq;
        for (ListNode *x:lists) if (x) pq.push({x->val, x});
        while (!pq.empty()) {
            ListNode *tmpMin = pq.top().second;
            pq.pop();
            pointer->next = tmpMin;
            if (tmpMin->next) pq.push({tmpMin->next->val, tmpMin->next});
            pointer = pointer->next;
        }
        res = res->next;
        return res;
    }
};