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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return NULL;
        ListNode *p = headA, *q = headB;
        while (p || q) {
            if (p == NULL && q == NULL)
                return NULL;
            if (p == q)
                return p;
            if (p)
                p = p->next;
            else 
                p = headB;
            if (q)
                q = q->next;
            else
                q = headA;
        }
        return NULL;
    }
};
