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
        if (head == NULL)
            return NULL;
        ListNode *p = head, *q;
        while (p && p->next) {
            if (p->val == p->next->val) {
                //remove
                q = p->next->next;
                delete (p->next);
                p->next = q;
            }
            else 
                p = p->next;
        }
        return head;
    }
};
