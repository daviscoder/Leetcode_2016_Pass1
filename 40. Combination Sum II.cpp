class Solution {
public:
    vector <vector<int>> helper (vector <int>& candidates, int target, int begin) {
        vector <vector<int>> res;
        for (int i = begin; i < candidates.size(); i++) {
            if (candidates[i] > target)
                break;
            else if (candidates[i] == target) {
                res.push_back (vector <int> (1, candidates[i]));
            }
            else {
                vector <vector<int>> tmp = helper (candidates, target - candidates[i], i + 1);
                for (int j = 0; j < tmp.size(); j++) {
                    vector <int> cur (1, candidates[i]);
                    cur.insert (cur.end(), tmp[j].begin(), tmp[j].end());
                    res.push_back (cur);
                }
            }
            while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) i++;
        }
        return res;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort (candidates.begin(), candidates.end());
        return helper (candidates, target, 0);
    }
};
