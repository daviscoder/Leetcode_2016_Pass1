// https://segmentfault.com/a/1190000003874375
class Solution {
public:
    
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> s;
        int min = INT_MIN;
        for (int i = 0; i < preorder.size(); i++) {
            if (preorder[i] < min) return false;
            while (s.empty() == false && s.top() < preorder[i]) {
                min = s.top();
                s.pop();
            }
            s.push (preorder[i]);
        }
        return true;
    }
};
