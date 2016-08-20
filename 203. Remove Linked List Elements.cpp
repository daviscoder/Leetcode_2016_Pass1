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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return NULL;
        ListNode * fakeHead = new ListNode (-1), *p = fakeHead;
        fakeHead->next = head;
        while (p) {
            if (p->next && p->next->val == val) {
                ListNode * q = p->next;
                p->next = q->next;
                delete (q);
            }
            else 
                p = p->next;
        }
        return fakeHead->next;
    }
};
