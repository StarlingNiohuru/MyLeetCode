using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// Use 3 pointers: odd, even and evenHead. Time complexity is O(n).
class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *odd = head, *even = head->next, *evenHead = even;
        while (even != NULL && even->next != NULL) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};