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
    unordered_map <int, int> my_map;
public:
    TreeNode* helper (int ileft, int iright, int pleft, int pright, vector<int>& postorder, vector<int>& inorder) {
        if (iright < ileft)
            return NULL;
        else if (iright == ileft)
            return new TreeNode (inorder [ileft]);
        TreeNode *p = new TreeNode (postorder [pright]);
        int i = my_map[p->val];
        int length = iright - i;
        p->left = helper (ileft, i - 1, pleft, pright - length - 1, postorder, inorder);
        p->right = helper (i + 1, iright, pright - length, pright - 1, postorder, inorder);
        return p;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0 || inorder.size() == 0 || postorder.size() != inorder.size())
            return NULL;
        for (int i = 0; i < inorder.size(); i++)
            my_map [inorder[i]] = i;
        return helper (0, inorder.size() - 1, 0, postorder.size() - 1, postorder, inorder);
    }
};
