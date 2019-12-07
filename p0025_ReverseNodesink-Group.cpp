using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// Use 4 pointers. "last" is used to find the last node of every k-group."stop" records the next k-group's first node
// and is used to cut off connection with "last". "first" is for reverse operation as "*head". "pre" is one node before
// "first" and is used to reconnect to the reversed sublist again.
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy, *stop = dummy->next;
        while (stop) {
            ListNode *first = stop, *last = stop;
            for (int i = 0; i < k - 1 && last; i++) last = last->next;
            if (last == NULL) break;
            stop = last;
            stop = stop->next;
            last->next = NULL;
            pre->next = reverseList(first);
            for (int i = 0; i < k; i++) pre = pre->next;
            pre->next = stop;
        }
        return dummy->next;
    }

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
};