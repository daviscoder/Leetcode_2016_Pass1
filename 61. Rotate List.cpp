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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
            return head;
        ListNode *prev = head, *p = head, *new_head;
        int length = 0;
        while (p) {
            p = p->next;
            length++;
        }
        k = k % length;
        if (k == 0)
            return head;
        p = head;
        for (int i = 0; i < k; i++)
            p = p->next;
        while (p && p->next) {
            p = p->next;
            prev = prev->next;
        }
        if (p) {
            new_head = prev->next;
            prev->next = NULL;
            p->next = head;
            return new_head;
        }
        else 
            return head;
    }
};
