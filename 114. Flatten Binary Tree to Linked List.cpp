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
    TreeNode* helper (TreeNode* root) {
        if (root == NULL)
            return NULL;
        TreeNode *left = helper (root->left);
        TreeNode *right = helper (root->right);
        if (left) {
            root->left = NULL;
            root->right = left;
            while (left->right)
                left = left->right;
            left->right = right;
        }
        return root;
    }
    void flatten(TreeNode* root) {
        helper (root);
    }
};
