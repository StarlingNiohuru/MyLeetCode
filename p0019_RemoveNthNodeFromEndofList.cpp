using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

//use 2 pointers with a length n gap between them.Time complexity is O(n), space complexity is O(1).
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(0), *front = dummy, *back = dummy;
        dummy->next = head;
        for (int i = 0; i < n; i++)
            front = front->next;
        while (front->next != NULL) {
            front = front->next;
            back = back->next;
        }
        back->next = back->next->next;
        return dummy->next;
    }
};