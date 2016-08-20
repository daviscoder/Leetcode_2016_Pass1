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
    ListNode* plusOne(ListNode* head) {
        stack<ListNode*> s;
        ListNode *p = head;
        while (p != NULL) {
            s.push (p);
            p = p->next;
        }
        int carry = 1;
        while (s.empty() == false && carry) {
            ListNode *cur = s.top();
            carry += cur->val;
            cur->val = carry % 10;
            carry /= 10;
            s.pop();
        }
        if (carry) {
            ListNode *newHead = new ListNode (1);
            newHead->next = head;
            return newHead;
        }
        return head;
    }
};
