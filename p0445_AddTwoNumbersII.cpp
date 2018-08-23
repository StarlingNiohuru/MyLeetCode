#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *res, *p;
        res = nullptr;
        vector<int> n1, n2;
        while (l1) {
            n1.push_back(l1->val);
            l1 = l1->next;
        };
        while (l2) {
            n2.push_back(l2->val);
            l2 = l2->next;
        };
        int i, j, carry, temp;
        i = n1.size() - 1, j = n2.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            temp = (i >= 0 ? n1[i--] : 0) + (j >= 0 ? n2[j--] : 0) + carry;
            carry = temp / 10;
            p = new ListNode(temp % 10);
            p->next = res;
            res = p;
        }
        return res;
    }
};
