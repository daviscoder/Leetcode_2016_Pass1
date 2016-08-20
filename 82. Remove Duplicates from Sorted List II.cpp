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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode * fakeHead = new ListNode (-1), *p = head, *prev = fakeHead;
        fakeHead->next = head;
        while (p && p->next) {
            if (p->val == p->next->val) {
                while (p->next && p->val == p->next->val) {
                    ListNode *tmp = p;
                    p = p->next;
                    free (tmp);
                }
                prev->next = p->next;
                delete(p);
                p = prev->next;
            }
            else {
                prev = p;
                p = p->next;
            }
        }
        return fakeHead->next;
    }
};
