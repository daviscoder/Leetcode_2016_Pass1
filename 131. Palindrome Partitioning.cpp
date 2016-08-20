class Solution {
public:
    bool isPalindrome (string s, int l, int r) {
        while (l <= r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    
    void helper (string s, int start, vector<string>& cur, vector<vector<string>>& res) {
        if (start == s.size()) {
            res.push_back (cur);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome (s, start, i)) {
                cur.push_back (s.substr (start, i - start + 1));
                helper (s, i + 1, cur, res);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        vector<vector<string>> res;
        if (s.size() == 0) return res;
        helper (s, 0, cur, res);
        return res;
    }
};
