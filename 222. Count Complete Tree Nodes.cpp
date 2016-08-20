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
    int countNodes(TreeNode* root) {
        int leftDep = leftDepth (root);
        int rightDep = rightDepth (root);
        if (leftDep == rightDep)
            return (1 << leftDep) - 1;
        return 1 + countNodes (root->left) + countNodes (root->right);
    }
    int leftDepth (TreeNode* root) {
        int depth = 0;
        while (root) {
            depth++;
            root = root->left;
        }
        return depth;
    }
    int rightDepth (TreeNode* root) {
        int depth = 0;
        while (root) {
            depth++;
            root = root->right;
        }
        return depth;
    }
};
