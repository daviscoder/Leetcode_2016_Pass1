/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *fakeHead_small = new ListNode (-1), *fakeHead_large = new ListNode (-1), *p = head, *q = fakeHead_small, *r = fakeHead_large;
        while (p) {
            if (p->val < x) {
                q->next = p;
                q = q->next;
            }
            else {
                r->next = p;
                r = r->next;
            }
            p = p->next;
        }
        q->next = fakeHead_large->next;
        r->next = NULL;
        return fakeHead_small->next;
    }
};
