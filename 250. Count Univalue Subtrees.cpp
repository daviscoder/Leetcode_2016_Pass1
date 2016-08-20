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
    int count;
    
    bool helper (TreeNode* root, int val) {
        if (root == NULL) return true;
        bool left = helper (root->left, root->val);
        bool right = helper (root->right, root->val);
        if (left == false || right == false)
            return false;
        count++;
        return val == root->val;
    }
    
    int countUnivalSubtrees(TreeNode* root) {
        count = 0;
        helper (root, -1);
        return count;
    }
};
