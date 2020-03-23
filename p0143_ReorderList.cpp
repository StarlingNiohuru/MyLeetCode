using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// First use 2 pointers(fast and slow) to find the middle node and divide it into half. Second, reverse the second half list.
// Third, merge the 2 lists. Time complexity is O(n).
class Solution {
private:
    ListNode *reverseList(ListNode *head) {
        ListNode *curr = head, *prev = NULL, *cons = NULL;
        while (curr != NULL) {
            cons = curr->next;
            curr->next = prev;
            prev = curr;
            curr = cons;
        }
        return prev;
    }

public:
    void reorderList(ListNode *head) {
        if (!head) return;
        ListNode *p1 = head, *p2 = head, *temp;
        while (p2->next && p2->next->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        p2 = p1->next;
        p1->next = NULL;
        p1 = head;
        p2 = reverseList(p2);
        while (p1 || p2) {
            temp = p1->next;
            p1->next = p2;
            p1 = temp;
            if (p2) {
                temp = p2->next;
                p2->next = p1;
                p2 = temp;
            }
        }
    }
};