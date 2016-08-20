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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
            return NULL;
        ListNode *p = head, *q = head;
        while (q->next && q->next->next) {
            q = q->next->next;
            p = p->next;
            if (p == q) {
                ListNode *r = head;
                while (r != p) {
                    r = r->next;
                    p = p->next;
                }
                return r;
            }
        }
        return NULL;
    }
};
