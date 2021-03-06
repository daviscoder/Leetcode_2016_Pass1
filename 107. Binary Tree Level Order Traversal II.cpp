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
    vector <vector<int>>res;
public:
    void helper (TreeNode* root, int level) {
        if (root == NULL)
            return;
        if (level >= res.size()) {
            vector <int> tmp;
            res.push_back (tmp);
        }
        res[level].push_back (root->val);
        helper (root->left, level + 1);
        helper (root->right, level + 1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        helper (root, 0);
        reverse (res.begin(), res.end());
        return res;
    }
};
