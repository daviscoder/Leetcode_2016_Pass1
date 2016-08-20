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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *fakeHead = new ListNode (-1), *p = fakeHead, *q = head;
        while (q && q->next) {
            ListNode *tmp = q->next;
            q->next = tmp->next;
            tmp->next = q;
            p->next = tmp;
            p = q;
            q = p->next;
        }
        return fakeHead->next;
    }
};
