using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// Time complexity is O(n).
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *dummy = new ListNode(0), *curr = dummy, *beforeM = dummy;
        dummy->next = head;
        int count = 0;
        while (count < m) {
            beforeM = curr;
            curr = curr->next;
            count++;
        }
        ListNode *prev = beforeM, *cons, *afterM = beforeM->next;
        while (count >= m && count <= n) {
            cons = curr->next;
            curr->next = prev;
            prev = curr;
            curr = cons;
            count++;
        }
        beforeM->next = prev;
        afterM->next = curr;
        return dummy->next;
    }
};