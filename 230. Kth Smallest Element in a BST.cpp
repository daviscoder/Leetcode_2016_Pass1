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
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        helper (root, k, res);
        return res;
    }
    
    void helper (TreeNode* root, int& k, int& res) {
        if (root == NULL || k <= 0) return;
        helper (root->left, k, res);
        if (k <= 0) return; // already found on left subtree.
        k--;
        if (k == 0) {
            res = root->val;
            return;
        }
        helper (root->right, k, res);
    }
};
