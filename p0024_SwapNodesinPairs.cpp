using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

//Iteration. 3 pointers in 4 steps.Time complexity is O(n), space complexity is O(1).
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummy = new ListNode(0), *p = dummy;
        dummy->next = head;
        while (p->next && p->next->next) {
            ListNode *p1 = p->next, *p2 = p->next->next;
            p->next = p2;
            p1->next = p2->next;
            p2->next = p1;
            p = p->next->next;
        }
        return dummy->next;
    };
};

//Iteration. 3 pointer2 in 5 steps.
class Solution2 {
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