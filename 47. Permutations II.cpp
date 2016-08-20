class Solution {
public:
    void helper (vector<vector<int>>& res, vector <int>& cur, vector<bool>& visited, vector<int>& nums) {
        if (cur.size() == nums.size()) {
            res.push_back (cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] == false) {
                if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == false) // 一个iteration里面同样数字不能选两次!
                    continue;
                cur.push_back (nums[i]);
                visited[i] = true;
                helper (res, cur, visited, nums);
                cur.pop_back ();
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector <vector<int>> res;
        vector <int> cur;
        vector <bool> visited (nums.size(), false);
        sort (nums.begin(), nums.end());
        helper (res, cur, visited, nums);
        return res;
    }
};
