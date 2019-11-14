using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// First use 2 pointers, slow and fast, to find the circle. When they meet, use another slow pointer from head.
// At last the two slow pointers must meet at the node where the circle begins. Because:
// distance(fast) = 2 distance(slow) => F + (a + b + a) = 2(F + a) => F = b (F is the distance before circle.
// a is from begin point to slow-fast meet point while b is from slow-fast meet point to begin point)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode *slow2 = head;
                while (slow != slow2) {
                    slow = slow->next;
                    slow2 = slow2->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

