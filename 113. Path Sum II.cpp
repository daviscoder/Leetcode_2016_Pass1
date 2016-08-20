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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector <vector <int>> res;
        if (root == NULL)
            return res;
        if (root->left == NULL && root->right == NULL && root->val == sum) {
            vector <int> tmp (1, root->val);
            res.push_back (tmp);
            return res;
        }
        if (root->left) {
            vector <vector <int>> tail = pathSum (root->left, sum - root->val);
            for (int i = 0; i < tail.size(); i++) {
                vector <int> tmp (1, root->val);
                tmp.insert (tmp.end(), tail[i].begin(), tail[i].end());
                res.push_back (tmp);
            }
        }
        if (root->right) {
            vector <vector <int>> tail = pathSum (root->right, sum - root->val);
            for (int i = 0; i < tail.size(); i++) {
                vector <int> tmp (1, root->val);
                tmp.insert (tmp.end(), tail[i].begin(), tail[i].end());
                res.push_back (tmp);
            }
        }
        return res;

    }
};
