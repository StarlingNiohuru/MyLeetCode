using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *preHead = new ListNode(0);
        ListNode *unsorted = head;
        while (unsorted) {
            ListNode *front = preHead;
            while (front->next && front->next->val <= unsorted->val) front = front->next;
            ListNode *temp = front->next;
            front->next = unsorted;
            unsorted = unsorted->next;
            if (front->next) front->next->next = temp;
        }
        return preHead->next;
    }
};