#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (head == nullptr) return true;
//        use 2 pointers, find the middle
        ListNode *fast = head, *slow = head;
        while ((fast->next != nullptr) && (fast->next->next != nullptr)) {
            slow = slow->next;
            fast = fast->next->next;
        }
//        reverse the 2nd half list
        ListNode *curr = slow->next, *prev = nullptr, *cons = nullptr;
        while (curr != nullptr) {
            cons = curr->next;
            curr->next = prev;
            prev = curr;
            curr = cons;
        }
//        compare two lists
        fast = prev, slow = head;
        while (fast != nullptr) {
            if (fast->val != slow->val) return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};