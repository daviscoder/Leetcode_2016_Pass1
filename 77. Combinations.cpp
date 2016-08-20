class Solution {
public:
    void helper (vector<vector<int>>& res, vector<int>& cur, int start, int cnt, int n, int k) {
        if (cnt == k) {
            res.push_back (cur);
            return;
        }
        for (int i = start; i + (k - cnt) <= n; i++) {
            cur.push_back (i + 1);
            helper (res, cur, i + 1, cnt + 1, n, k);
            cur.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
//        vector<bool> visited (n, false);
        vector<vector<int>> res;
        vector<int> cur;
        if (k == 0)
            return res;
        helper (res, cur, 0, 0, n, k);
        return res;
    }
};
