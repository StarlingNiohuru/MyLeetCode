using namespace std;

// Use 2 pointers from headA and headB respectively. When p1 from headA reaches NULL, let p1=headB and continue.
// Same with p2 from headB. If 2 lists have intersection, p1 and p2 must meet at intersection point. Otherwise they will
// reach NULL at the same time. Time complexity is O(m+n). Space complexity is O(1).
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        if (!p1 || !p2) return NULL;
        while (p1 && p2 && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
            if (p1 == p2) return p1;
            if (!p1) p1 = headB;
            if (!p2) p2 = headA;
        }
        return p1;
    }
};