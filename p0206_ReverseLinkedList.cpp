#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *curr = head, *prev = nullptr, *cons = nullptr;
        while (curr != nullptr) {
            cons = curr->next;
            curr->next = prev;
            prev = curr;
            curr = cons;
        }
        return prev;
    }
};