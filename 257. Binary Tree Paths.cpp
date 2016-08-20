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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector <string> res;
        if (root == NULL)
            return res;
        if (root->left == NULL && root->right == NULL)
            res.push_back (to_string (root->val));
        else {
            string cur = to_string (root->val);
            cur.append ("->");
            if (root->left) {
                vector <string> tmp = binaryTreePaths (root->left);
                for (int i = 0; i < tmp.size(); i++) {
                    string new_str = cur;
                    new_str.append (tmp[i]);
                    res.push_back (new_str);
                }
            }
            if (root->right) {
                vector <string> tmp = binaryTreePaths (root->right);
                for (int i = 0; i < tmp.size(); i++) {
                    string new_str = cur;
                    new_str.append (tmp[i]);
                    res.push_back (new_str);
                }
            }
        }
        return res;
    }
};
