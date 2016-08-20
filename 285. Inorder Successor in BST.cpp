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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = NULL;
        while (root != p) {
            if (root->val > p->val) {
                successor = root;
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        if (root->right) {
            root = root->right;
            while (root->left) {
                root = root->left;
            }
            return root;
        }
        return successor;
    }
};
