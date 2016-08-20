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
    int longest = 0;
    void helper (TreeNode * root, int len) {
        longest = max (len, longest);
        if (root->left && root->left->val == root->val + 1)
            helper (root->left, len + 1);
        else if (root->left)
            helper (root->left, 1);
        if (root->right && root->right->val == root->val + 1)
            helper (root->right, len + 1);
        else if (root->right)
            helper (root->right, 1);
    }

    int longestConsecutive(TreeNode* root) {
        if (root)
            helper (root, 1);
        return longest;
    }
};
