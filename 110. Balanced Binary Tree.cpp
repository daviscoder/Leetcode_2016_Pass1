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
    int depth (TreeNode * root) {
        if (root == NULL)
            return 0;
        int left_depth = depth (root->left);
        int right_depth  = depth (root->right);
        if (abs (left_depth - right_depth) > 1 || left_depth == -1 || right_depth == -1)
            return -1;
        return max (left_depth, right_depth) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        return depth (root) != -1;
    }
};
