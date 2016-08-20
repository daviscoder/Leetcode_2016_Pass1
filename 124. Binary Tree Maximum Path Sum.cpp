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
private:
    int res = INT_MIN;
public:
    int helper (TreeNode* root) {
        if (root == NULL) return 0;
        int left = max (0, helper (root->left));
        int right = max (0, helper (root->right));
        res = max (res, left + right + root->val);
        return max (left, right) + root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        helper (root);
        return res;
    }
};
