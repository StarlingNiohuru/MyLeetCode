using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

//use 2 pointers with n intervals
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *front = head, *back = head;
        for (int i = 0; i < n; i++)
            front = front->next;
        if (front == NULL) return head->next;
        while (front->next != NULL) {
            front = front->next;
            back = back->next;
        }
        back->next = back->next->next;
        return head;
    }
};