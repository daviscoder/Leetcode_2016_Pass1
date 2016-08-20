/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)
            return NULL;
        else if (head->next == NULL) {
            TreeNode *res = new TreeNode (head->val);
            return res;
        }
        ListNode *slow = head, *fast = head, *prev;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = NULL;
        TreeNode *res = new TreeNode (slow->val);
        res->left = sortedListToBST (head);
        res->right = sortedListToBST (slow->next);
        return res;
    }
};
