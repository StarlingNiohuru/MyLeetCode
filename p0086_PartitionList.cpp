using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// Use 2 pointers.Time complexity is O(n).
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *p1 = new ListNode(0), *p2 = new ListNode(0), *curr = head, *dummy1 = p1, *dummy2 = p2;
        while (curr) {
            if (curr->val < x) {
                p1->next = curr;
                p1 = p1->next;
            } else {
                p2->next = curr;
                p2 = p2->next;
            }
            curr = curr->next;
        }
        p2->next = NULL;
        p1->next = dummy2->next;
        return dummy1->next;
    }
};