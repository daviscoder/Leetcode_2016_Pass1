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
    void helper (TreeNode* root, int& num, int& res) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            num = num * 10 + root->val;
            res += num;
            num /= 10;
            return;
        }
        num = num * 10 + root->val;
        helper (root->left, num, res);
        helper (root->right, num, res);
        num /= 10;
    }
    
    int sumNumbers(TreeNode* root) {
        int num = 0, res = 0;
        helper (root, num, res);
        return res;
    }
};
