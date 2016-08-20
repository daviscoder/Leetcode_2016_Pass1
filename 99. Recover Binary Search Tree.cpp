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
    TreeNode *p1 = NULL;
    TreeNode *p2 = NULL;
    TreeNode *prev;
public:
    void traverse (TreeNode* root) {
        if (root == NULL) return;
        traverse (root->left);
        if (p1 == NULL && root->val < prev->val)
            p1 = prev;
        if (p1 != NULL && root->val < prev->val)
            p2 = root;
        prev = root;
        traverse (root->right);
    }

    void recoverTree(TreeNode* root) {
        prev = new TreeNode (INT_MIN);
        traverse (root);
        int tmp = p1->val;
        p1->val = p2->val;
        p2->val = tmp;
    }
};
