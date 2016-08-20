class Solution {
public:
    vector<vector<int>> helper (int k, int n, int begin) {
        vector <vector<int>> res;
        if (k == 0)
            return res;
        for (int i = begin; i <= 9; i++) {
            if (i == n && k == 1)
                res.push_back (vector <int> (1, i));
            else if (i > n || (i == n && k > 1))
                break;
            else {
                vector <vector<int>> tmp = helper (k - 1, n - i, i + 1);
                for (int j = 0; j < tmp.size(); j++) {
                    vector <int> cur (1, i);
                    cur.insert (cur.end(), tmp[j].begin(), tmp[j].end());
                    res.push_back (cur);
                }
            }
        }
        return res;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        return (helper (k, n, 1));
    }
};
