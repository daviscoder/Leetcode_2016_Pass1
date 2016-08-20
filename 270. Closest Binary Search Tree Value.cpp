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
public:
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        if (root->left && target < root->val) {
            int tmp = closestValue (root->left, target);
            res = abs(target - tmp) < abs (target - res)? tmp : res;
        }
        else if (root->right && target > root->val) {
            int tmp = closestValue (root->right, target);
            res = abs(target - tmp) < abs (target - res)? tmp : res;
        }
        return res;
  }
};
