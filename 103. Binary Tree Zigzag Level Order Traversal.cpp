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
    vector<vector<int>> res;
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

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        helper (root, 0);
        for (int i = 1; i < res.size(); i += 2) {
            reverse (res[i].begin(), res[i].end());
        }
        return res;
    }
};
