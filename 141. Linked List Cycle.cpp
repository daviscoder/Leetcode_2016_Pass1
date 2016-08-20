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
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return false;
        ListNode *fast = head, *slow = head;
        while (slow && fast) {
            if (slow->next)
                slow = slow->next;
            else 
                break;
            if (fast->next && fast->next->next)
                fast = fast->next->next;
            else
                break;
            if (slow == fast)
                return true;
        }
        return false;
    }
};
