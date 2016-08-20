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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * fakeHead = new ListNode (-1), *p = fakeHead;
        int carry = 0;
        while (l1 || l2 || carry) {
            int tmp = carry;
            if (l1) {
                tmp += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                tmp += l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode (tmp % 10);
            carry = tmp / 10;
            p = p->next;
        }
        return fakeHead->next;
    }
};
