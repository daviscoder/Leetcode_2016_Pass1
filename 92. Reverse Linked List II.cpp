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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL)
            return NULL;
        ListNode *fakeHead = new ListNode (-1), *p = fakeHead, *new_end, *q, *r;
        fakeHead->next = head;
        for (int i = 0; i < m - 1; i++)
            p = p->next;
        new_end = p->next;
        q = new_end;
        r = q->next;
        for (int i = 0; i < n - m; i++) {
            ListNode * tmp = r->next;
            r->next = q;
            q = r;
            r = tmp;
        }
        p->next = q;
        new_end->next = r;
        return fakeHead->next;
    }
};
