class Solution {
public:

    vector <vector<int>> helper (vector <int>& candidates, int start, int target) {
        vector <vector<int>> res;
        for (int i = start; i < candidates.size(); i++) {
            if (target > candidates[i]) {
                vector <vector<int>> tmp = helper (candidates, i, target - candidates[i]);
                for (int j = 0; j < tmp.size(); j++) {
                    vector <int> cur (1, candidates[i]);
                    cur.insert (cur.end(), tmp[j].begin(), tmp[j].end());
                    res.push_back (cur);
                }
            }
            else if (target == candidates[i])
                res.push_back (vector <int> (1, candidates[i]));
            else
                break;
        }
        return res;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <vector<int>> res;
        if (candidates.size() <= 0)
            return res;
        sort (candidates.begin(), candidates.end());
        return helper (candidates, 0, target);
    }
};
