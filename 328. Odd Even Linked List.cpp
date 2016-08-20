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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oddHead = new ListNode (-1), *evenHead = new ListNode (-1), *p = head, *q = oddHead, *r = evenHead;
        while (p && p->next) {
            q->next = p;
            p = p->next;
            r->next = p;
            p = p->next;
            q = q->next;
            r = r->next;
        }
        if (p) {
            q->next = p;
            q = q->next;
        }
        q->next = evenHead->next;
        r->next = NULL;
        return oddHead->next;
    }
};
