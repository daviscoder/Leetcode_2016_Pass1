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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return NULL;
        ListNode *fakeHead = new ListNode (-1), *p = fakeHead, *q = fakeHead;
        fakeHead->next = head;
        for (int i = 0; i < n; i++) {
            p = p->next;
        }
        while (p->next) {
            p = p->next;
            q = q->next;
        }
        p = q->next;
        q->next = q->next->next;
        delete (p);
        return fakeHead->next;
    }
};
