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
    bool isValid (TreeNode* root, int left, int right) {
        if (root == NULL)
            return true;
        if (root->val == INT_MIN && root->left)
            return false;
        if (root->val == INT_MAX && root->right)
            return false;
        if (root->val > right || root->val < left)
            return false;
        return isValid (root->left, left, root->val - 1) && isValid (root->right, root->val + 1, right);
    }

    bool isValidBST(TreeNode* root) {
        return isValid (root, INT_MIN, INT_MAX);
    }
};
