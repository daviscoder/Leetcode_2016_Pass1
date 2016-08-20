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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode *fakeHead = new ListNode (-1), *p, *q = head, *prev;
        while (q) {
            ListNode *tmp = q;
            p = fakeHead;
            while (p && p->val < tmp->val || p == fakeHead) {
                prev = p;
                p = p->next;
            }
            q = q->next;
            prev->next = tmp;
            tmp->next = p;
        }
        return fakeHead->next;
    }
};
