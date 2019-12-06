using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *preHead = new ListNode(0);
        preHead->next = head;
        ListNode *pointer = preHead;
        while (pointer->next && pointer->next->next) {
            ListNode *a = pointer->next;
            ListNode *b = pointer->next->next;
            pointer->next = b;
            b = b->next;
            pointer->next->next = a;
            a->next = b;
            pointer = pointer->next->next;
        }
        return preHead->next;
    }
};