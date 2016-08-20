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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        TreeNode * p = root, * lastVisit = NULL;
        while (s.empty() == false || p) {
            while (p) {
                s.push (p);
                p = p->left;
            }
            p = s.top();
            if (p->right == NULL || p->right == lastVisit) {
                lastVisit = p;
                res.push_back (p->val);
                s.pop();
                p = NULL;
            }
            else {
                p = p->right;
            }
        }
        return res;
    }
};
