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
    vector<TreeNode*> helper(int start, int end) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back (NULL);
            return res;
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> l = helper(start, i - 1);
            vector<TreeNode*> r = helper (i + 1, end);
            for (int j = 0; j < l.size(); j++) {
                for (int k = 0; k < r.size(); k++) {
                    TreeNode *p = new TreeNode (i);
                    p->left = l[j];
                    p->right = r[k];
                    res.push_back (p);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0)
            return vector <TreeNode*> ();
        return helper (1, n);
    }
};
