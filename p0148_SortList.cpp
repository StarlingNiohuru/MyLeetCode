using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// use merge sort
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *mid = findMid(head);
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(mid);
        return mergeList(l1, l2);
    }
// find the middle node and split the list at the middle node
private:
    ListNode *findMid(ListNode *head) {
        ListNode *front = head;
        ListNode *back = head;
        while (front && front->next) {
            front = front->next->next;
            if (!front || !front->next) {
                ListNode *tmp = back->next;
                back->next = NULL;
                back = tmp;
            } else back = back->next;
        }
        return back;
    }

private:
    ListNode *mergeList(ListNode *l1, ListNode *l2) {
        ListNode *sorted = new ListNode(0);
        ListNode *pointer = sorted;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                pointer->next = l1;
                l1 = l1->next;
            } else {
                pointer->next = l2;
                l2 = l2->next;
            }
            pointer = pointer->next;
        }
        pointer->next = l1 ? l1 : l2;
        sorted = sorted->next;
        return sorted;
    }
};