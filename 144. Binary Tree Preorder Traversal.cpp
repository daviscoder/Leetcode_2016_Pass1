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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL)
            return result;
        stack <TreeNode *> s;
        TreeNode *p = root;
        while (!s.empty() || p) {
            if (p) {
                result.push_back (p->val);
                s.push (p->right);
                p = p->left;
            }
            else {
                p = s.top();
                s.pop();
            }
        }
        return result;
    }
};
