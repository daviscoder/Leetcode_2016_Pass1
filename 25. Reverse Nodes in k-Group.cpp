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
    ListNode* reverse (ListNode* head, int k) {
        ListNode *p = head, *q = p->next, *tmp;
        for (int i = 0; i < k - 1; i++) {
            tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
        }
        return p;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * fakeHead = new ListNode (-1), *p = fakeHead;
        fakeHead->next = head;
        while (p) {
            ListNode *prevSeg = p;
            for (int i = 0; i < k && p; i++)
                p = p->next;
            if (!p) break;
            ListNode *nextSeg = p->next;
            ListNode *newTail = prevSeg->next;
            ListNode *newHead = reverse (prevSeg->next, k);
            prevSeg->next = newHead;
            newTail->next = nextSeg;
            p = newTail;
        }
        return fakeHead->next;
    }
};
