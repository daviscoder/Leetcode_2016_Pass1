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
    TreeNode* helper (int ileft, int iright, int pleft, int pright, vector<int>& preorder, vector<int>& inorder) {
        if (iright < ileft)
            return NULL;
        else if (iright == ileft)
            return new TreeNode (inorder [ileft]);
        TreeNode *p = new TreeNode (preorder [pleft]);
        int i = my_map[p->val];
        int length = i - ileft;
        p->left = helper (ileft, i - 1, pleft + 1, pleft + length, preorder, inorder);
        p->right = helper (i + 1, iright, pleft + length + 1, pright, preorder, inorder);
        return p;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0 || preorder.size() != inorder.size())
            return NULL;
        for (int i = 0; i < inorder.size(); i++)
            my_map [inorder[i]] = i;
        return helper (0, inorder.size() - 1, 0, preorder.size() - 1, preorder, inorder);
    }
};
