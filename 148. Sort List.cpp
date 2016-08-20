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
    ListNode* sortList(ListNode* head) {
        // 0 or 1 element only.
        if (head == NULL || head->next == NULL)
            return head;
        // find middle point.
        ListNode *slow = head, * fast = head, *prev;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = NULL;
        // recursion.
        ListNode *leftHead = sortList (head);
        ListNode *rightHead = sortList (slow);
        // Merge.
        ListNode *fakeHead = new ListNode (-1), *p = fakeHead, *q = leftHead, *r = rightHead;
        while (q && r) {
            if (q->val < r->val) {
                p->next = q;
                q = q->next;
            }
            else {
                p->next = r;
                r = r->next;
            }
            p = p->next;
        }
        if (q)
            p->next = q;
        if (r)
            p->next = r;
        return fakeHead->next;
    }
};
