/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode *> my_stack;
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            my_stack.push (root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !my_stack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *p = my_stack.top();
        int res = p->val;
        my_stack.pop();
        p = p->right;
        while (p) {
            my_stack.push (p);
            p = p->left;
        }
        return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
