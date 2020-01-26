using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// Time complexity is O(n).
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dummy = new ListNode(INT32_MAX);
        dummy->next = head;
        ListNode *curr = dummy, *temp;
        while (curr->next && curr->next->next) {
            temp = curr->next;
            if (temp->val == temp->next->val) {
                while (temp->next && temp->val == temp->next->val) temp = temp->next;
                curr->next = temp->next;
            } else curr = temp;
        }
        return dummy->next;
    }
};