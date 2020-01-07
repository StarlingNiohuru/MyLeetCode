using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// We can figure out that every part's length is n / k + ((i < n % k) ? 1 : 0). Then cut them off one by one.
// Time complexity is O(n).
class Solution {
public:
    vector<ListNode *> splitListToParts(ListNode *root, int k) {
        vector<ListNode *> res;
        int n = 0;
        ListNode *curr = root, *tail;
        while (curr != NULL) {
            curr = curr->next;
            n++;
        }
        curr = root;
        for (int i = 0; i < k; i++) {
            res.push_back(curr);
            for (int j = 0; j < n / k + ((i < n % k) ? 1 : 0) - 1; j++) curr = curr->next;
            if (curr != NULL) {
                tail = curr;
                curr = curr->next;
                tail->next = NULL;
            }
        }
        return res;
    }
};