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
    vector<vector<int>> res;
    int helper (TreeNode* root) {
        if (root == NULL) return 0;
        int left = helper (root->left);
        int right = helper (root->right);
        int curLevel = max(left, right);
        if (res.size() <= curLevel)
            res.push_back (vector<int> ());
        res[curLevel].push_back (root->val);
        return curLevel + 1;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        helper (root);
        return res;
    }
};
