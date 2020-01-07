using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// First traverse the list to find the tail and length of the list (n). Then we connect the tail to head and go ahead
// n - k % n steps to the new tail. At last we cut off the link between new head (new_tail->next) and new tail.
// Time complexity is O(n).
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) return NULL;
        ListNode *curr = head;
        int n = 1;
        while (curr->next != NULL) {
            curr = curr->next;
            n++;
        }
        curr->next = head;
        for (int i = 0; i < n - k % n; i++) curr = curr->next;
        ListNode *res = curr->next;
        curr->next = NULL;
        return res;
    }
};