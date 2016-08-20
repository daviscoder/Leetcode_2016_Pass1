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
    bool helper (TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL)
            return true;
        else if (left != NULL && right != NULL && left->val == right->val) {
            return helper (left->left, right->right) && helper (left->right, right->left);
        }
        else
            return false;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return helper (root->left, root->right);
    }
};
