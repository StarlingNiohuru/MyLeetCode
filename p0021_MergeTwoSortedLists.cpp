using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *res = new ListNode(0);
        ListNode *point = res;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                point->next = l1;
                l1 = l1->next;
            } else {
                point->next = l2;
                l2 = l2->next;
            }
            point = point->next;
        }
        if (l1 == NULL) point->next = l2;
        if (l2 == NULL) point->next = l1;
        res = res->next;
        return res;
    }
};