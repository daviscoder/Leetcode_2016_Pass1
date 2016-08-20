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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode *p = NULL, *q = head;
        while (q) {
            ListNode *tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
        }
        return p;
    }
    
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;
        ListNode *fast = head, *slow = head;
        // Find Middle Point.
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Reverse Second Half. q will be the new head.
        ListNode *tmp_0 = slow, *p, *q;
        slow = slow->next;
        tmp_0->next = NULL;
        q = reverseList (slow);
        // Merge.
        p = head;
        ListNode * fakeHead = new ListNode (-1), *r = fakeHead;

        while (p && q) {
            cout << r->val;
            r->next = p;
            r = r->next;
            p = p->next;
            r->next = q;
            q = q->next;
            r = r->next;
        }
        if (p)
            r->next = p;
    }
};
